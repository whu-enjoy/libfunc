op=debug

ifeq ($(op),debug)
	CFLAGS=-Wall -c -ggdb -I../include
else
	CFLAGS=-Wall -c -O2 -I../include
endif

CC=gcc
RM=-rm
OBJ_DIR=../obj/

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,$(OBJ_DIR)%.o, $(SRC))

all:$(OBJ)

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) -f $(OBJ)

.PHONY: all clean
