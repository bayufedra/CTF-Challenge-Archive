import hashlib
from stringencrypt import StringEncrypt

myStringEncrypt = StringEncrypt("D8B8-ECE5-07FF-6289")
myStringEncrypt.outputProgrammingLanguage = StringEncrypt.OutputProgrammingLanguages.LANG_CPP
myStringEncrypt.minEncryptionCommands = 50
myStringEncrypt.maxEncryptionCommands = 50
myStringEncrypt.useUnicode = False

def md5(s):
    return hashlib.md5(s.encode('utf-8')).hexdigest()


flag = 'TSA{N1c3_D3bugg1n9_Sk1llz!}'
for i, c in enumerate(flag):
    print(f'Generating {i} -> {c}')
    result = myStringEncrypt.encrypt_string(c, "enc")
    source = result['source']
    source = source.replace('\n', '\n    ')
    code = f"""
__attribute__((section(".{md5(str(i))}")))void process{i}(char c) {{
    {source}if (enc[0] == c) {{
        decrypt(".{md5(str(i+1))}", md5(enc));
    }}
}}
"""
    print(code)