CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic

BIN = tree
OBJ = binary_tree.o

library: $(OBJ)
	ar csr libbinary_tree.a $^

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o libbinary_tree.a $(BIN)
