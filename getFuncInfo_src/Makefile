op=debug

ifeq ($(op),debug)
	CFLAGS=-Wall -c -ggdb -I./include -I./
else
	CFLAGS=-Wall -c -O2 -I./include -I./
endif

CC=gcc
RM=-rm
MAKE=make
SUB_DIR=choose
SUB_DIR+=funcNameArray
SUB_DIR+=main
CLEAN_DIR=$(addprefix _clean_,$(SUB_DIR))
LD=gcc
OBJ_DIR=./obj/
TARGET=getFuncInfo
SRC=$(wildcard funcNameArray/*.c main/*.c choose/*.c)
OBJ=$(patsubst %c,$(OBJ_DIR)%o,$(notdir $(SRC)))

all:$(TARGET) 

$(TARGET):$(SUB_DIR)
	$(LD) $(OBJ) -o ../$@
	@echo "说明程序./getFuncInfo创建成功!"
	@echo ""

$(SUB_DIR):
	@echo "entry $@"
	$(MAKE) -C $@ op=$(op)

clean:$(CLEAN_DIR)
	$(RM) -f ../$(TARGET)
	
$(CLEAN_DIR):
	$(MAKE) -C $(patsubst _clean_%,%,$@) clean

.PHONY: $(SUB_DIR) $(CLEAN_DIR)
