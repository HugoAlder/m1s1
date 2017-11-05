CC		= gcc
CFLAGS	= -m32

ALL := display_stack try

all: ${ALL}

%: %.c
	${CC} $< ${CFLAGS} -o $@ 

clean:
	rm ${ALL} || true

.PHONY: all clean realclean
