from pwn import *
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

def cipher(pt, keys):
    left, right = pt >> 32 & 0xffffffff, pt & 0xffffffff
    
    left, right = left, right ^ left
    num_round = 4
    for i in range(num_round):
        left, right = left ^ f(right, keys[i]), right
        if i == num_round - 1:
            break
        left, right = right, left
    left, right = left, right ^ left

    assert left < 2 ** 32
    assert right < 2 ** 32
    return ((left << 32) | (right))

def decrypt(msg, keys):
    decrypted = b''
    dec_keys = [keys[3], keys[2], keys[1], keys[0]]
    for i in range(len(msg) // 8):
        decrypted += long_to_bytes(cipher(bytes_to_long(msg[8 * i:8 * (i + 1)]), dec_keys))
    return decrypted

LOCAL = 0
if LOCAL:
    conn = process(['python3', 'chall.py'])
else:
    conn = remote('localhost', 9999)

conn.sendlineafter(b'> ', b'2')
flag = unhexlify(conn.recvuntil(b'\n').strip())

n = 8
plaintexts1 = []
plaintexts2 = []
ciphertexts1 = []
ciphertexts2 = []

for i in range(n):
    pt1 = urandom(8)
    pt2 = long_to_bytes(bytes_to_long(pt1) ^ 0x8000000080000000)

    conn.sendlineafter(b'> ', b'1')
    conn.sendlineafter(b'message (hex): ', hexlify(pt1))
    ct1 = unhexlify(conn.recvuntil(b'\n').strip())

    conn.sendlineafter(b'> ', b'1')
    conn.sendlineafter(b'message (hex): ', hexlify(pt2))
    ct2 = unhexlify(conn.recvuntil(b'\n').strip())

    plaintexts1.append(pt1)
    plaintexts2.append(pt2)
    ciphertexts1.append(ct1)
    ciphertexts2.append(ct2)

args = ['3', str(0x00080000), str(n)]
for i in range(n):
    enc1 = ciphertexts1[i][:8]
    enc2 = ciphertexts2[i][:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2

    args.append(str(left1))
    args.append(str(right1))
    args.append(str(left2))
    args.append(str(right2))

guessed_k3 = int(popen('go run crack.go %s' % ' '.join(args)).read().strip())
print(f'{guessed_k3 = }')

args = ['2', str(0x80000000), str(n)]
for i in range(n):
    enc1 = ciphertexts1[i][:8]
    enc2 = ciphertexts2[i][:8]
    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2
    
    left1, right1 = right1, left1 ^ f(right1, guessed_k3)
    left2, right2 = right2, left2 ^ f(right2, guessed_k3)

    args.append(str(left1))
    args.append(str(right1))
    args.append(str(left2))
    args.append(str(right2))

guessed_k2 = int(popen('go run crack.go %s' % ' '.join(args)).read().strip())
print(f'{guessed_k2 = }')

args = ['1', str(n)]
for i in range(n):
    a1 = plaintexts1[i][:8]
    a2 = plaintexts2[i][:8]
    enc1 = ciphertexts1[i][:8]
    enc2 = ciphertexts2[i][:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2
    
    left1, right1 = right1, left1 ^ f(right1, guessed_k3)
    left2, right2 = right2, left2 ^ f(right2, guessed_k3)

    left1, right1 = right1, left1 ^ f(right1, guessed_k2)
    left2, right2 = right2, left2 ^ f(right2, guessed_k2)

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

args = ['0', str(n)]
for i in range(n):
    a1 = plaintexts1[i][:8]
    a2 = plaintexts2[i][:8]
    enc1 = ciphertexts1[i][:8]
    enc2 = ciphertexts2[i][:8]

    left1 = bytes_to_long(enc1[:4])
    right1 = bytes_to_long(enc1[4:8]) ^ left1
    left2 = bytes_to_long(enc2[:4])
    right2 = bytes_to_long(enc2[4:8]) ^ left2
    
    left1, right1 = right1, left1 ^ f(right1, guessed_k3)
    left2, right2 = right2, left2 ^ f(right2, guessed_k3)

    left1, right1 = right1, left1 ^ f(right1, guessed_k2)
    left2, right2 = right2, left2 ^ f(right2, guessed_k2)

    left1, right1 = right1, left1 ^ f(right1, guessed_k1)
    left2, right2 = right2, left2 ^ f(right2, guessed_k1)

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


keys = [guessed_k0, guessed_k1, guessed_k2, guessed_k3]

print(decrypt(flag, keys))