#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// gcc pwn.c -o pwn -no-pie -fno-pic -fno-stack-protector -z execstack

void secret(){
        system("/bin/sh");
}

void __init__(){
        setvbuf(stdin,0,2,0);
        setvbuf(stdout,0,2,0);
}

int main(){
        __init__();

        char buff[128];

        printf("[>] Nama: ");
        gets(buff);
        printf("[*] Welcome, %s!\n", &buff);
        return 0;
}