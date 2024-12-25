import lief
import hashlib
import sys

def md5(data):
    return hashlib.md5(data.encode()).hexdigest()

bin = lief.parse(sys.argv[1])
flag = 'TSA{N1c3_D3bugg1n9_Sk1llz!}'

with open(sys.argv[1], "rb") as f:
    content = bytearray(f.read())

for i in range(len(flag)):
    if i == 0:
        continue

    section_text = bin.get_section("." + md5(str(i)))
    print(f"Encrypting {section_text.offset:x}...")
    key = md5(flag[i - 1])
    for j in range(len(section_text.content)):
        content[section_text.offset + j] ^= ord(key[j % len(key)])

with open(sys.argv[1] + "_enc", "wb") as f:
    f.write(content)