#!/usr/bin/env python3
from pwn import *

context.arch = "amd64"

# r = process("./chall")
if len(sys.argv) != 3:
    print(f"{sys.argv[0]} HOST PORT")
    exit(255)

r = remote(sys.argv[1], int(sys.argv[2]))

r.sendline("%p")

assert (r.recvline(0).startswith(b"0x"))

r.interactive()
