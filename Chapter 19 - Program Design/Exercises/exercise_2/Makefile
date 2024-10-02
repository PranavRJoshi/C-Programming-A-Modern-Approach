CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

all: exercise_2

exercise_2: exercise_2.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_2.o: exercise_2.c stack.h
	$(CC) $(CFLAGS) -c $<

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm stack.o exercise_2.o exercise_2

