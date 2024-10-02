CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

all: exercise_5

exercise_5: exercise_5.o queue.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_5.o: exercise_5.c queue.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm queue.o exercise_5.o exercise_5

