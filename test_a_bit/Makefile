CC = gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -ggdb3 -fsanitize=address
LDLIBS=-fsanitize=address

EXEC = main
SRC = main.c is_set.c
OBJ = ${SRC:.c=.o}

all: ${EXEC}

${EXEC}: ${OBJ}
		${CC} ${CFLAGS} $^ ${LDLIBS} -o $@

clean:
	rm -f ${OBJ}
	rm -f ${EXEC}
