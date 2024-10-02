CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_3

project_3: project_3.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

project_3.o: project_3.c readline.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_3 project_3.o readline.o
