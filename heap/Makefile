CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic

BIN = heap
OBJ = add.o \
	  create.o \
	  del.o \
	  pop.o \
	  print.o

library: $(OBJ)
	ar csr libheap.a $^

$(BIN): $(OBJ) main.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o libheap.a $(BIN)
