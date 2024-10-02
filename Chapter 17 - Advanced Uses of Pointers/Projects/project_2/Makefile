CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_2

project_2: project_2.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

project_2.o: project_2.c utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_2 project_2.o utils.o


