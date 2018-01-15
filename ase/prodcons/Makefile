CC	= gcc
CFLAGS	= -m32

LIB_ROOT = hardware
INCS     = -I$(LIB_ROOT)/include
LIBS     = -L$(LIB_ROOT)/lib -lhardware

ALL := prodcons

all: $(ALL)

prodcons: prodcons.o ctx.o sem.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

prodcons.o: prodcons.c
	$(CC) $(CFLAGS) -c $< $(INCS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< $(INCS)

clean:
	rm *.o && rm $(ALL) || true

.PHONY: all clean
