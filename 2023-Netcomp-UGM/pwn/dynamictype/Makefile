CC = gcc
CFLAGS = -Wall -Wextra -no-pie -fPIC -fstack-protector-all -s

SRC = src/main.c
OBJ = $(SRC:.c=.o)
EXEC = chall

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o release/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)

