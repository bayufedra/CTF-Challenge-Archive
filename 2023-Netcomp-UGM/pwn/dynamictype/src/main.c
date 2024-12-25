#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXPOOL 8

const char *MENU = "1. CREATE\n"
                   "2. VIEW\n"
                   "3. DELETE\n"
                   "choose: ";
union Object {
  char *p_str;
  long d_long;
  double d_double;
};

union Object *pool = NULL;

void setup() {
  setbuf(stdout, 0);
  setbuf(stdin, 0);

  pool = malloc(64);
  if (!pool) {
    perror("pool allocation failed");
    exit(EXIT_FAILURE);
  }
}

double get_double(const char *msg) {
  char buf[16];
  printf("%s", msg);
  read(STDIN_FILENO, buf, 15);
  return atof(buf);
}

size_t get_ulong(const char *msg) {
  char buf[16];
  printf("%s", msg);
  read(STDIN_FILENO, buf, 15);
  return strtoul(buf, NULL, 10);
}

int create() {
  char tmp[64];

  size_t idx = get_ulong("index: ");
  if (idx >= MAXPOOL) {
    return EXIT_FAILURE;
  }

  size_t type = get_ulong("type: ");
  if (type < 1 || type > 3) {
    return EXIT_FAILURE;
  }

  switch (type) {
  case 1:
    printf("data: ");
    read(STDIN_FILENO, tmp, 63);
    pool[idx].p_str = strdup(tmp);
    break;
  case 2:
    pool[idx].d_long = get_ulong("data: ");
    break;
  case 3:
    pool[idx].d_double = get_double("data: ");
    break;
  }

  return EXIT_SUCCESS;
}

int view() {
  size_t idx = get_ulong("index: ");
  if (idx >= MAXPOOL) {
    return EXIT_FAILURE;
  }

  size_t type = get_ulong("type: ");
  if (type < 1 || type > 3) {
    return EXIT_FAILURE;
  }

  printf("data: ");

  switch (type) {
  case 1:
    printf("%s\n", pool[idx].p_str);
    break;
  case 2:
    printf("%ld\n", pool[idx].d_long);
    break;
  case 3:
    printf("%lf\n", pool[idx].d_double);
    break;
  }

  return EXIT_SUCCESS;
}

int delete() {
  size_t idx = get_ulong("index: ");
  if (idx >= MAXPOOL) {
    return EXIT_FAILURE;
  }

  size_t type = get_ulong("type: ");
  if (type < 1 || type > 3) {
    return EXIT_FAILURE;
  }

  if (type == 1)
    free(pool[idx].p_str);

  pool[idx].p_str = NULL;

  return EXIT_SUCCESS;
}

int main() {
  size_t choice = 0;
  int ret = EXIT_SUCCESS;
  long gap;

  setup();

  for (;;) {
    choice = get_ulong(MENU);

    switch (choice) {
    case 1:
      ret = create();
      break;
    case 2:
      ret = view();
      break;
    case 3:
      ret = delete();
      break;
    default:
      ret = EXIT_FAILURE;
    }

    if (ret) {
      puts("invalid.");
    }
  }

  return EXIT_SUCCESS;
}
