#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOTESZ 0x40
#define MAXNOTES 8

char key[8] = {0};
char **notes;
size_t *notesz;

const char *MENU = "1. CREATE\n"
                   "2. VIEW\n"
                   "3. DELETE\n"
                   "choose: ";

void helper() {
  asm volatile("pop %%rdi\n\t"
               "ret"
               :
               :
               : "rdi");
}

void xormsg(char *ptr, size_t size) {
  for (size_t i = 0; i < size; ++i)
    ptr[i] ^= key[i % 8];
}

void setup() {
  uint64_t *pivot;

  setbuf(stdout, 0);
  setbuf(stdin, 0);

  asm("movq %%rbp, %0" : "=r"(pivot));

  for (; *pivot != 25; pivot++)
    ;

  (*(uint64_t *)key) = (**((uint64_t **)++pivot));

  notes = calloc(MAXNOTES, sizeof(char *));
  if (!notes) {
    puts("oom error. hubungi admin.");
    exit(1);
  }

  notesz = calloc(MAXNOTES, sizeof(size_t *));
  if (!notesz) {
    puts("oom error. hubungi admin.");
    exit(1);
  }
}

uint64_t get_ulong(const char *msg) {
  char buf[14];
  printf("%s", msg);
  fgets(buf, 0x100, stdin);
  return strtoul(buf, NULL, 10);
}

int create() {
  uint64_t idx = get_ulong("index: ");
  if (idx >= MAXNOTES || notes[idx] != NULL) {
    return 1;
  }

  uint64_t size = get_ulong("size: ");
  if (size > NOTESZ) {
    return 1;
  }

  notes[idx] = calloc(size, 1);
  if (notes[idx] == NULL) {
    puts("oom error. hubungi admin.");
    exit(1);
  }

  notesz[idx] = size;

  printf("notes: ");
  fgets(notes[idx], notesz[idx], stdin);

  return 0;
}

int view() {
  char buf[NOTESZ + 1] = {0};
  int decrypt = 0;

  uint64_t idx = get_ulong("index: ");
  if (idx >= MAXNOTES || notes[idx] == NULL || notesz[idx] == 0) {
    return 1;
  }

  memset(buf, 0, NOTESZ);

  printf("decrypt? (y/n): ");
  fgets(buf, 7, stdin);

  decrypt = buf[0] == 'y';
  memcpy(buf, notes[idx], notesz[idx]);

  if (!decrypt)
    xormsg(buf, notesz[idx]);

  fwrite(buf, 1, notesz[idx], stdout);

  return 0;
}

int delete() {
  uint64_t idx = get_ulong("index: ");
  if (idx >= MAXNOTES || notes[idx] == NULL) {
    return 1;
  }

  memset(notes[idx], 0, NOTESZ);
  free(notes[idx]);
  notes[idx] = NULL;

  return 0;
}

int main() {
  size_t menu = 0;
  int ret = 0;

  setup();

  for (;;) {
    menu = get_ulong(MENU);

    switch (menu) {
    case 1:
      ret = create();
      break;
    case 2:
      ret = view();
      break;
    case 3:
      ret = delete ();
      break;
    default:
      ret = 1;
    }

    if (ret) {
      puts("invalid.");
    }
  }

  return 0;
}
