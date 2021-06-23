SHELL=/bin/bash
CC?=gcc-10
CFLAGS=-g -O3 -z lazy
CLIB=-lm
SRC=$(wildcard *.c)
TARGET=$(patsubst %.c, %, $(SRC))

all: ${TARGET}
%:	%.c
	${CC} ${CFLAGS} $@.c -o $@ ${CLIB}

clean:
	rm -f ${TARGET}
