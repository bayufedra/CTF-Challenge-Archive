from binascii import hexlify, unhexlify
from os import urandom, popen
from Crypto.Util.number import long_to_bytes, bytes_to_long

def h(x, n):
    return (x >> (n * 8)) & 0xff

def g(x, y, z):
    res = (3*x + 5*y + 7*z) % 0x100
    return ((res << 4) | (res >> 4)) & 0xff

def f(x, key):
    x ^= key
    out_0 = g(h(x, 0), h(x, 1), 0)
    out_1 = g(h(x, 2), h(x, 1) ^ out_0, 1)
    out_2 = g(h(x, 2) ^ out_1, h(x, 3), 0)
    out_3 = g(h(x, 3), h(x, 3), 1)

    return ((out_3 << 24) | (out_2 << 16) | (out_1 << 8) | (out_0))

def cipher(pt, keys, verbose=False):
    left, right = pt >> 32 & 0xffffffff, pt & 0xffffffff
    
    left, right = left, right ^ left
    num_round = 4
    for i in range(num_round):
        left, right = left ^ f(right, keys[i]), right
        if verbose:
            print(f'round {i}')
            print(f'{left = }')
            print(f'{right = }')
        if i == num_round - 1:
            break
        left, right = right, left
    left, right = left, right ^ left
    if verbose:
        print('=======')

    assert left < 2 ** 32
    assert right < 2 ** 32
    return ((left << 32) | (right))

def pad(msg):
    return msg + chr(8 - len(msg) % 8).encode() * (8 - len(msg) % 8)

def encrypt(msg, keys, verbose=False):
    encrypted = b''
    enc_keys = [keys[0], keys[1], keys[2], keys[3]]
    msg = pad(msg)
    for i in range(len(msg) // 8):
        encrypted += long_to_bytes(cipher(bytes_to_long(msg[8 * i:8 * (i + 1)]), enc_keys, verbose))
    return encrypted

def decrypt(msg, keys):
    decrypted = b''
    dec_keys = [keys[3], keys[2], keys[1], keys[0]]
    for i in range(len(msg) // 8):
        decrypted += long_to_bytes(cipher(bytes_to_long(msg[8 * i:8 * (i + 1)]), dec_keys))
    return decrypted

keys = [bytes_to_long(urandom(4)) for _ in range(4)]
#keys = [100, 200, 300, 400]
msg = urandom(16)
enc = encrypt(msg, keys)
dec = decrypt(enc, keys)
assert pad(msg) == dec

# karakteristik g box (peluang 100% selalu benar, didapat dari find_diff_characteristic.go):
# input1, input2, output
# 0, 0, 0
# 0, 128, 8
# 128, 0, 8
# 128, 128, 0

# karakteristik f box (didapat dari analisis g box di atas dan analisis algoritma f-box)
# 0x80000000 -> 0x00080000
a1 = bytes_to_long(urandom(4))
a2 = a1 ^ 0x80000000
k = bytes_to_long(urandom(4))
assert f(a1, k) ^ f(a2, k) == 0x00080000

# generate some plaintext-ciphertexts and they will be useful to checking every differential to recover keys
n = 8

# recover k3
print(f'{keys[3] = }')

args = ['3', str(0x00080000), str(n)]
for i in range(n):
    a1 = urandom(8)
    a2 = long_to_bytes(bytes_to_long(a1) ^ 0x8000000080000000)
    enc1 = encrypt(a1, keys)[:8]
    enc2 = encrypt(a2, keys)[:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2

    args.append(str(left1))
    args.append(str(right1))
    args.append(str(left2))
    args.append(str(right2))

    # sanity check
    #fake_left1 = left1 ^ f(right1, keys[3])
    #fake_left2 = left2 ^ f(right2, keys[3])
    #assert fake_left1 ^ fake_left2 == 0x00080000

guessed_k3 = int(popen('go run crack.go %s' % ' '.join(args)).read().strip())
print(f'{guessed_k3 = }')
test_pt = urandom(8)
enc = encrypt(test_pt, keys)
print(f'{bytes_to_long(pad(test_pt)) = }')
print(f'{bytes_to_long(enc) = }')
keys[3] = guessed_k3
dec = decrypt(enc, keys)
print(f'{bytes_to_long(dec) = }')
assert dec == pad(test_pt)


# recover k2
print(f'{keys[2] = }')

args = ['2', str(0x80000000), str(n)]
for i in range(n):
    a1 = urandom(8)
    a2 = long_to_bytes(bytes_to_long(a1) ^ 0x8000000080000000)
    enc1 = encrypt(a1, keys)[:8]
    enc2 = encrypt(a2, keys)[:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2
    
    left1, right1 = right1, left1 ^ f(right1, keys[3])
    left2, right2 = right2, left2 ^ f(right2, keys[3])


    args.append(str(left1))
    args.append(str(right1))
    args.append(str(left2))
    args.append(str(right2))

    # sanity check
    #fake_left1 = left1 ^ f(right1, keys[2])
    #fake_left2 = left2 ^ f(right2, keys[2])
    #assert fake_left1 ^ fake_left2 == 0x80000000

guessed_k2 = int(popen('go run crack.go %s' % ' '.join(args)).read().strip())
print(f'{guessed_k2 = }')
test_pt = urandom(8)
enc = encrypt(test_pt, keys)
print(f'{bytes_to_long(pad(test_pt)) = }')
print(f'{bytes_to_long(enc) = }')
keys[2] = guessed_k2
dec = decrypt(enc, keys)
print(f'{bytes_to_long(dec) = }')
assert dec == pad(test_pt)


# recover k1
print(f'{keys[1] = }')

args = ['1', str(n)]
for i in range(n):
    a1 = urandom(8)
    a2 = long_to_bytes(bytes_to_long(a1) ^ 0x8000000080000000)
    enc1 = encrypt(a1, keys)[:8]
    enc2 = encrypt(a2, keys)[:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2
    
    left1, right1 = right1, left1 ^ f(right1, keys[3])
    left2, right2 = right2, left2 ^ f(right2, keys[3])

    left1, right1 = right1, left1 ^ f(right1, keys[2])
    left2, right2 = right2, left2 ^ f(right2, keys[2])

    right1_from_top = bytes_to_long(a1[4:8]) ^ bytes_to_long(a1[:4])
    right2_from_top = bytes_to_long(a2[4:8]) ^ bytes_to_long(a2[:4])

    output1_f_k1 = left1 ^ right1_from_top
    output2_f_k1 = left2 ^ right2_from_top

    args.append(str(output1_f_k1))
    args.append(str(right1))
    args.append(str(output2_f_k1))
    args.append(str(right2))

guessed_k1 = int(popen('go run crack.go %s' % ' '.join(args)).read().strip())
print(f'{guessed_k1 = }')
test_pt = urandom(8)
enc = encrypt(test_pt, keys)
print(f'{bytes_to_long(pad(test_pt)) = }')
print(f'{bytes_to_long(enc) = }')
keys[1] = guessed_k1
dec = decrypt(enc, keys)
print(f'{bytes_to_long(dec) = }')
assert dec == pad(test_pt)


# recover k0
print(f'{keys[0] = }')

args = ['0', str(n)]
for i in range(n):
    a1 = urandom(8)
    a2 = long_to_bytes(bytes_to_long(a1) ^ 0x8000000080000000)
    enc1 = encrypt(a1, keys)[:8]
    enc2 = encrypt(a2, keys)[:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2
    
    left1, right1 = right1, left1 ^ f(right1, keys[3])
    left2, right2 = right2, left2 ^ f(right2, keys[3])

    left1, right1 = right1, left1 ^ f(right1, keys[2])
    left2, right2 = right2, left2 ^ f(right2, keys[2])

    left1, right1 = right1, left1 ^ f(right1, keys[1])
    left2, right2 = right2, left2 ^ f(right2, keys[1])

    right1_from_top = bytes_to_long(a1[4:8]) ^ bytes_to_long(a1[:4])
    right2_from_top = bytes_to_long(a2[4:8]) ^ bytes_to_long(a2[:4])
    left1_from_top = bytes_to_long(a1[:4])
    left2_from_top = bytes_to_long(a2[:4])

    output1_f_k0 = left1 ^ left1_from_top
    output2_f_k0 = left2 ^ left2_from_top

    args.append(str(output1_f_k0))
    args.append(str(right1_from_top))
    args.append(str(output2_f_k0))
    args.append(str(right2_from_top))

guessed_k0 = int(popen('go run crack.go %s' % ' '.join(args)).read().strip())
print(f'{guessed_k0 = }')
test_pt = urandom(8)
enc = encrypt(test_pt, keys)
print(f'{bytes_to_long(pad(test_pt)) = }')
print(f'{bytes_to_long(enc) = }')
keys[0] = guessed_k0
dec = decrypt(enc, keys)
print(f'{bytes_to_long(dec) = }')
assert dec == pad(test_pt)