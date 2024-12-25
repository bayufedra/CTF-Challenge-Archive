enc_flag = [84, 77, 71, 62, 72, 118, 77, 98, 101, 103, 98, 90, 83, 67, 107, 101, 88, 94, 92, 76, 62, 80, 96, 78, 90, 90, 75, 68, 41, 81, 73, 74, 78, 68, 67, 79, 69, 73, 65, 86]
# print(''.join(chr(j-i) for i,j in enumerate(enc_flag)))

flag = ""

for i,j in enumerate(enc_flag):
	flag += chr(i-j)
print(flag)
	