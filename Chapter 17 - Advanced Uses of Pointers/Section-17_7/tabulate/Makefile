CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: tabulate

tabulate: tabulate.o
	$(CC) $(CFLAGS) -o $@ $<

tabulate.o: tabulate.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm tabulate tabulate.o
