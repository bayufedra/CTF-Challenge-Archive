#include <stdio.h>
#include <string.h>

void setup() {
  setbuf(stdout, 0);
  setbuf(stdin, 0);
}

void pwn() {
  char buf[256];
  memset(buf, 0, sizeof buf);

  for (;;) {
    fgets(buf, sizeof(buf) - 1, stdin);

    if (buf[0] == '\n')
      break;

    printf(buf);
  }
}

int main() {
  long gap;

  setup();
  pwn();

  return 0;
}
