CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

all: exercise_3

exercise_3: exercise_3.o queue_1.o queue_2.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_3.o: exercise_3.c queue_1.h
	$(CC) $(CFLAGS) -c $<

queue_1.o: queue_1.c queue_1.h
	$(CC) $(CFLAGS) -c $<

queue_2.o: queue_2.c queue_2.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm queue_1.o queue_2.o exercise_3.o exercise_3


