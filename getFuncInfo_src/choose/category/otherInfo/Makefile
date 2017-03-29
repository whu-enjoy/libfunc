op=debug

ifeq ($(op),debug)
	CFLAGS=-Wall -c -ggdb -I./include -I../include
else
	CFLAGS=-Wall -c -O2 -I./include -I../include
endif

CC=gcc
RM=-rm
MAKE=make
SUB_DIR=src
LD=ld
LD_FLAGS=-r
OBJ_DIR=./obj/
TARGET=otherInfo.o
SRC=$(wildcard *.c src/*.c)
OBJ=$(patsubst %c,$(OBJ_DIR)%o,$(notdir $(SRC)))

all:$(TARGET) 

$(TARGET):
	$(MAKE) -C $(SUB_DIR) op=$(op)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)$(TARGET) $(patsubst %o,%c,$(TARGET))
	$(LD) $(LD_FLAGS) $(OBJ) -o ../obj/$@
	
clean:
	$(MAKE) -C $(SUB_DIR) $@
	$(RM) -f ../obj/$(TARGET)
	$(RM) -f $(OBJ_DIR)$(TARGET)

.PHONY: all clean
