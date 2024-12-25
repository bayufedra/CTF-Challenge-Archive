// gcc -pie -g -fstack-protector -Wl,-z,now -o main main.c
// BUG: array size out of bound when insert note more than 6 which can overwrite ptr[0]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

struct {
	unsigned int size[6];
	char* ptr[6];
	unsigned long num_active;
} gdata;

static inline int readline(char* buf, int len) {
	int n;
	n = read(0, buf, len);
	if(n < 0) {
		printf("Read error\n");
		exit(1);
	}
	if(buf[n-1] == '\n') {
		buf[n-1] = '\0';
	}
	return n;
}

unsigned int readint() {
	char buf[25];
	int res;
	readline(buf, 25);
	res = strtol(buf, NULL, 10);
	return res;
}

void alloc_note() {
	unsigned int size, i;
	printf("Index: ");
	i = readint();
	if(i>6) {
		printf("Index too big\n");
		return;
	}
	if(gdata.ptr[i]) {
		printf("Invalid index\n");
		return;
	}
	printf("Size: ");
	gdata.size[i] = readint();
	gdata.ptr[i] = malloc(gdata.size[i]);
	if(gdata.ptr[i] == NULL) {
		printf("Malloc error");
		return;
	}
	printf("Data: ");
	readline(gdata.ptr[i], gdata.size[i]);
	gdata.num_active++;
	printf("There are %ld notes active\n", gdata.num_active);
}

void edit_note() {
	unsigned int idx;
	printf("Index: ");
	idx = readint();
	if(idx > 6 || gdata.ptr[idx] == NULL) {
		printf("Invalid");
		return;
	}
	printf("New data: ");
	readline(gdata.ptr[idx], gdata.size[idx]);
}

void free_note() {
	unsigned int idx;
	printf("Index: ");
	idx = readint();
	if(idx > 6 || gdata.ptr[idx] == NULL) {
		printf("Invalid");
		return;
	}
	gdata.num_active--;
	free(gdata.ptr[idx]);
	printf("Done\n");
	gdata.ptr[idx] = NULL;
	gdata.size[idx] = 0;
}


void timeout(int n) {
	printf("Timeout!\n");
	exit(1);
}

int init_prog(void) {
	setvbuf(stdin,(char *)0x0,2,0);
	setvbuf(stdout,(char *)0x0,2,0);
	setvbuf(stderr,(char *)0x0,2,0);
	alarm(60);
	signal(SIGALRM, timeout);
}

void menu() {
	printf("====== MENU ======\n");
	printf("[1] Alloc\n");
	printf("[2] Edit\n");
	printf("[3] Free\n");
	printf("[4] Exit\n");
	printf("> ");
}


int main(int argc, char** argv)
{
	init_prog();
	int c;
	while(1) {
		menu();
		printf("Your choice: ");
		c = readint();
		switch(c) {
			case 1:
				alloc_note();
				break;
			case 2:
				edit_note();
				break;
			case 3:
				free_note();
				break;
			case 4:
				printf("Bye!\n");
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}
	}
done:
	return 0;
}
