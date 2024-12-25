from Crypto.Util.number import bytes_to_long
from py_ecc import bn128 as lib
from secrets import randbelow

p = lib.field_modulus

flag = b'netcomp{math_M4TH_123}'
m = randbelow(p)

GF1 = GF(p)
E1 = EllipticCurve(GF1, [0, 3])
G1 = E1(1, 2)
G1m = G1 * m
print(f'{G1m = }')

# parameters from bn128 curve
GF2 = GF(p**2, 'a', modulus=x^2+1)
E2 = EllipticCurve(GF2, [0, GF2([3, 0]) / GF2([9, 1])])
G2 = E2(
    GF2([10857046999023057135944570762232829481370756359578518086990519993285655852781, 11559732032986387107991004021392285783925812861821192530917403151452391805634]),
    GF2([8495653923123431417604973247489272438418190587263600148770280649306958101930, 4082367875863433681332203403145435568316851327593401208105741076214120093531]),
)
G2m = G2 * m
print(f'{G2m = }')

# parameters from bn128 curve
GF12 = GF(p**12, 'a', modulus=x^12-18*x^6+82)

pairing_g2_g1 = GF12(eval(str(lib.pairing(lib.G2, lib.G1))))
enc = ((pairing_g2_g1^(m^2))^127) * bytes_to_long(flag)
print(f'{enc = }')