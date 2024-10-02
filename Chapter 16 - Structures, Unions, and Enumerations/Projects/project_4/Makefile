CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_4

project_4: project_4.o readline.o
	$(CC) $(CFLAGS) -o $@ $^

project_4.o: project_4.c readline.h
	$(CC) $(CFLAGS) -c $<

readline.o: readline.c readline.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_4 project_4.o readline.o
