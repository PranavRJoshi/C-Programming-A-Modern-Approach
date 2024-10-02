CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_2

project_2: project_2.o readline.o quicksort.o
	$(CC) $(CFLAGS) -o $@ $^

project_2.o: project_2.c readline.h quicksort.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<

quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_2 project_2.o readline.o quicksort.o

