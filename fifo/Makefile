CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic

BIN = fifo
OBJ = fifo_access.o \
	  fifo_setup_destroy.o

library: $(OBJ)
	ar csr libfifo.a $^

clean:
	$(RM) *.o libfifo.a $(BIN)
