#!/usr/bin/env python3

from Crypto.Util.number import long_to_bytes, inverse

c = 432129069781466954970115267255448126809679346680737712720914
p = 1089915817272225657529571741047
q = 1230438593754451648545439211911
e = 65537
n = p * q
d = inverse(e, (p-1)*(q-1))

decrypt = pow(c, d, n)
decrypt = long_to_bytes(decrypt)

print(decrypt)

