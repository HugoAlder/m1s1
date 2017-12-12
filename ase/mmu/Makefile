CC	= gcc
CFLAGS	= -m32 -Wall -ansi -pedantic
CFLAGS  += -g

INCDIR  = -Iinclude
LIBS    = -Llib -lhardware

ALL = bin/static_mmu bin/test_mmu bin/mmu_manager bin/oracle

all: $(ALL)

bin/tlb: bin/tlb.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/swap: bin/swap.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/matrix: bin/matrix.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/user_process: bin/user_process.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/test_mmu: bin/test_mmu.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/static_mmu: bin/static_mmu.o bin/tlb.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/mmu_manager: bin/mmu_manager.o bin/user_process.o bin/swap.o bin/tlb.o bin/matrix.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/oracle: bin/oracle.o bin/matrix.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCDIR)

%: %.c

.PHONY: clean

clean:
	$(RM) bin/*
