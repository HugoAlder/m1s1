CC	= gcc
CFLAGS	= -m32 -Wall -ansi -pedantic
CFLAGS  += -g

INCDIR  = -Iinclude
LIBS    = -Llib -lhardware

ALL = bin/mkhd bin/dmps bin/frmt

all: $(ALL)

bin/mkhd: bin/mkhd.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/dmps: bin/dmps.o bin/drive.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/frmt: bin/frmt.o bin/drive.o
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCDIR)

%: %.c

.PHONY: clean realclean
clean:
	$(RM) bin/*
realclean: clean
	$(RM) vdiskA.bin vdiskB.bin
