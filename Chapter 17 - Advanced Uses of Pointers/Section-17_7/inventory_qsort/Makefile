CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: inventory_qsort

inventory_qsort: inventory_qsort.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

inventory_qsort.o: inventory_qsort.c readline.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm inventory_qsort inventory_qsort.o readline.o

