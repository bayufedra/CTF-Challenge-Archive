#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// gcc pwn.c -o pwn -no-pie -fno-pic -fno-stack-protector -z execstack

void __init__(){
        setvbuf(stdin,0,2,0);
        setvbuf(stdout,0,2,0);
}

int main(){
	__init__();

	int backdoor = 31337;
	char buff[128];

	printf("[>] Nama: ");
	gets(&buff);

	if (backdoor == 0xdeadc0de){
		printf("\n");
		printf("[*] Backdoor actived\n");
		printf("[*] Access granted...\n");
		system("/bin/sh");
	} else {
		printf("[*] Welcome %s!\n", &buff);
	}

	return 0;
}
