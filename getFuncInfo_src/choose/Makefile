op=debug

ifeq ($(op),debug)
	CFLAGS=-Wall -c -ggdb -I./include -I../include
else
	CFLAGS=-Wall -c -O2 -I./include -I../include
endif

CC=gcc
RM=-rm
MAKE=make
SUB_DIR=category
SUB_DIR+=initial
CLEAN_DIR=$(addprefix _clean_,$(SUB_DIR))
LD=ld
LD_FLAGS=-r
OBJ_DIR=./obj/
TARGET=choose.o
SRC=$(wildcard *.c category/*.c initial/*.c)
OBJ=$(patsubst %c,$(OBJ_DIR)%o,$(notdir $(SRC)))

all:$(TARGET) 

$(TARGET):$(SUB_DIR)
	$(CC) $(CFLAGS) -o $(OBJ_DIR)$(TARGET) $(patsubst %o,%c,$(TARGET))
	$(LD) $(LD_FLAGS) $(OBJ) -o ../obj/$@
	

$(SUB_DIR):
	$(MAKE) -C $@ op=$(op)

clean:$(CLEAN_DIR)
	$(RM) -f ../obj/$(TARGET)
	$(RM) -f $(OBJ_DIR)$(TARGET)
	
$(CLEAN_DIR):
	$(MAKE) -C $(patsubst _clean_%,%,$@) clean

.PHONY: $(SUB_DIR) $(CLEAN_DIR)
