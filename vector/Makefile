CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic

BIN = vector
OBJ = vector.o

library: $(OBJ)
	ar csr libvector.a $^

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o libvector.a $(BIN)
