CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_6

project_6: project_6.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

project_6.o: project_6.c utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_6 project_6.o utils.o
