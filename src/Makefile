BUILDDIR = ../build/
CODE = ../code-samples/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: clean Quest_1 Quest_2 Quest_3

Quest_1: state_sort.o fun.o bin_fun.o
	$(CC) state_sort.o fun.o bin_fun.o -o $(BUILDDIR)Quest_1

Quest_2: state_search.o fun_for_search.o bin_fun.o fun.o
	$(CC) state_search.o fun_for_search.o bin_fun.o fun.o -o $(BUILDDIR)Quest_2

Quest_3: clear_state.o fun_for_clean.o bin_fun.o fun.o
	$(CC) clear_state.o fun_for_clean.o bin_fun.o fun.o -o $(BUILDDIR)Quest_3

state_search.o: state_search.c
	$(CC) $(CFLAGS) -c state_search.c -o state_search.o

state_sort.o: state_sort.c
	$(CC) $(CFLAGS) -c state_sort.c -o state_sort.o

clear_state.o: clear_state.c
	$(CC) $(CFLAGS) -c clear_state.c -o clear_state.o

fun_for_search.o: fun_for_search.c
	$(CC) $(CFLAGS) -c fun_for_search.c -o fun_for_search.o

fun_for_clean.o: fun_for_clean.c
	$(CC) $(CFLAGS) -c fun_for_clean.c -o fun_for_clean.o

fun.o: fun.c
	$(CC) $(CFLAGS) -c fun.c -o fun.o

bin_fun.o: bin_fun.c
	$(CC) $(CFLAGS) -c bin_fun.c -o bin_fun.o

rebuild:
	clean Quest_1

clean: 
	rm -rf *.o
	rm -f $(BUILDDIR)Quest_1
	rm -f $(BUILDDIR)Quest_2
	rm -f $(BUILDDIR)Quest_3