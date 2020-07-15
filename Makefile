include config.mk

SRC=$(wildcard src/*.c)
SRC+=lib/cofyc/argparse/argparse.c
OBJ=$(SRC:.c=.o)

INCLUDES?=
INCLUDES+=-Iinc
INCLUDES+=-Ilib/cofyc/argparse

.c.o: $(@:.o=.c)
	$(CC) $(CFLAGSG) $(INCLUDES) $^ -c -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)
