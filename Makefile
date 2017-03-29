OP=debug
MAKE=make
RM=-rm
CP=cp
CC=gcc
LD=gcc
CFLAG=-Wall -c -fPIC -I./include
LDFLAG=-shared

USR_LIB=/usr/lib/
USR_BIN=/usr/bin/

SRC=$(wildcard src/*.c)
OBJ=$(patsubst %c,%o,$(SRC))
TARGET=libfunc.so
EXE=getFuncInfo
EXEDIR=getFuncInfo_src

.PHONY: all clean install uninstall

all:$(TARGET) $(EXE)

$(EXE):
	$(MAKE) -C $(EXEDIR) op=$(OP)

$(TARGET):$(OBJ)
	$(LD) $(LDFLAG) -o $@ $^

.c.o:
	$(CC) $(CFLAG) -o $@ $<

clean:
	$(MAKE) -C $(EXEDIR) $@
	$(RM) -f $(OBJ) $(TARGET)

install:
	$(CP) $(TARGET) $(USR_LIB)
	$(CP) $(EXE) $(USR_BIN)

uninstall:
	$(RM) -f $(USR_LIB)$(TARGET)
	$(RM) -f $(USR_BIN)$(EXE)
