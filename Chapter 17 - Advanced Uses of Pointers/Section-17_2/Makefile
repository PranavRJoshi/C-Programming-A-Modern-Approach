CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: remind2

remind2: remind2.o
	$(CC) $(CFLAGS) -o $@ $<

remind2.o: remind2.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm remind2
