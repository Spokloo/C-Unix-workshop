CC = gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -Wvla -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address
LDLIBS=-lcriterion

NAME=simple_fnmatch
TESTNAME=testsuite
TESTSUITE=tests/testsuite

all: $(NAME).c main.c
	$(CC) $(CFLAGS) -o $(NAME) $^

check: $(NAME).o $(TESTSUITE).o
	$(CC) $(CFLAGS) -o $(TESTNAME) $^ $(LDFLAGS) $(LDLIBS)
	./$(TESTNAME)

$(TESTSUITE).o: $(TESTSUITE).c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) tests/*.o *.o $(TESTNAME) $(NAME)
	$(RM) *.html *.css tests/*.gcno *.gcno tests/*.gcda *.gcda
