BUILDDIR = ../build/
CODE = ../code-samples/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: Quest_1

Quest_1: state_sort.o fun.o bin_fun.o
	$(CC) state_sort.o fun.o bin_fun.o -o $(BUILDDIR)Quest_1

state_sort.o: state_sort.c
	$(CC) -c state_sort.c -o state_sort.o

fun.o: fun.c
	$(CC) -c fun.c -o fun.o

bin_fun.o: bin_fun.c
	$(CC) -c bin_fun.c -o bin_fun.o

rebuild:
	clean Quest_1

clean: 
	rm -rf *.o
	rm -f $(BUILDDIR)Quest_1