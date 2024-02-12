CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic

BIN = dlist
OBJ = threshold1.o \
	  threshold2.o \
	  threshold3.o

library: $(OBJ)
	ar csr libdlist.a $^

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o libdlist.a $(BIN)
