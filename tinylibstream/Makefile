CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -Wvla -pedantic
LDFLAGS=-fsanitize=address

BIN = libstream
OBJ = src/lbs_fopen.o src/lbs_fdopen.o src/lbs_fclose.o src/lbs_fflush.o src/lbs_fputc.o src/lbs_fgetc.o

library: $(OBJ)
	ar csr libstream.a $^

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) src/*.o libstream.a $(BIN)
