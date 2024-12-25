#!/usr/bin/env python3

from Crypto.Util.number import *
from pwn import *
import re

def solver(c, e, n, ppq):
	d = (n+1) - ppq
	d = inverse(e, d)
	m = pow(c, d, n)
	return long_to_bytes(m)

nc = remote("103.127.99.15", 5000)
solve = 0

for i in range(30):
	chall = nc.recvuntil("[TOKEN]> ").decode()
	pubkey = re.findall("= (.*?)\n", chall)
	n = int(pubkey[0])
	e = int(pubkey[1])
	c = int(pubkey[2])
	ppq = int(pubkey[3])
	ans = solver(c, e, n, ppq)
	nc.sendline(ans)

	print(f"[TOKEN {solve}] {ans}")
	solve += 1

print(nc.recvall())
