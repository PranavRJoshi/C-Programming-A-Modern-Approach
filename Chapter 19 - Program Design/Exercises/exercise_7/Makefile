CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=exercise_7
OBJS=stackADT3.o exercise_7.o

all: exercise_7

exercise_7: exercise_7.o stackADT3.o
	$(CC) $(CFLAGS) -o $@ $^

exercise_7.o: exercise_7.c stackADT3.h
	$(CC) $(CFLAGS) -c $<

stackADT3.o: stackADT3.c stackADT3.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)

