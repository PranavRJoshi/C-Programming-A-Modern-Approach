CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: parts_db

parts_db: inventory.o readline.o 
	$(CC) $(CFLAGS) -o parts_db inventory.o readline.o

inventory.o: inventory.c readline.h
	$(CC) $(CFLAGS) -c inventory.c

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c readline.c

clean:
	rm parts_db inventory.o readline.o
