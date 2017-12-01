CC	= gcc
CFLAGS	= -m32 -Wall -ansi -pedantic
CFLAGS  += -g

INCDIR  = -Iinclude
LIBS    = -Llib -lhardware

ALL = bin/test_mmu

all: $(ALL)

bin/tlb: bin/tlb.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/test_mmu: bin/test_mmu.o bin/tlb.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCDIR)

%: %.c

.PHONY: clean

clean:
	$(RM) bin/*
