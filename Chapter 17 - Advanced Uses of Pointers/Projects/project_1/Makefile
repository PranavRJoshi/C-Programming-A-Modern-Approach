CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_1

project_1: project_1.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

project_1.o: project_1.c utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_1 project_1.o utils.o

