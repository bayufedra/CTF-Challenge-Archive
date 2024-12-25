#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i, k;
char p[100], l[50], r[50];

int cl(){
	int ll[] = {235, 237, 252, 199, 233, 255, 230, 137, 135, 135, 234, 129, 129, 128, 212, 210, 153, 207, 153, 148, 154, 158};

	for (int x=0; x<strlen(l); x++){
		if ((int)(l[x] ^ 0xbf ^ x) != ll[x]){
			exit(0);
		}
	}

	return 0;
}

int cr(){
	int lr[] = {55, 96, 33, 65, 51, 34, 110, 6, 90, 15, 49, 15, 91, 93, 95, 12, 64, 64, 19, 25, 71, 92};

	for (int y=0; y<strlen(r); y++){
		if (((int)(l[y]) ^ (int)(r[y]) ^ y) != lr[y]){
			exit(0);
		}
	}
	
	return 0;
}

int m(){
	printf("[>] FLAG: ");
	scanf("%s", p);

	int lo = strlen(p);
	int c = lo/2;
	
	for (i=0; i<c; i++){
		l[i] = p[i];
	}
	l[i] = '\0';
	
    for (i=c, k=0; i<=lo; i++, k++){
        r[k] = p[i];
    }
	
	cl();
	cr();
	
	printf("[CORRECT] %s\n", p);
	return 0;
}

int main(){
	m();
	return 0;
}
