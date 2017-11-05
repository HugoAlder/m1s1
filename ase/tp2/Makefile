CC		= gcc
CFLAGS	= -m32 -w

ALL := main yield

all: ${ALL}

%: %.c
	${CC} $< ${CFLAGS} -o $@

clean:
	rm ${ALL} || true

.PHONY: all clean realclean
