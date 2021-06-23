SHELL=/bin/bash
CC?=gcc-10
CFLAGS=-g
CLIB=-lm
SRC=$(wildcard *.c)
TARGET=$(patsubst %.c, %, $(SRC))

all: ${TARGET}
%:	%.c
	${CC} ${CFLAGS} $@.c -o $@ ${CLIB}

clean:
	rm -f ${TARGET}

