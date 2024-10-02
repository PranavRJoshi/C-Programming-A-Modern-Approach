CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: project_5

project_5: project_5.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

project_5.o: project_5.c utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm project_5 project_5.o utils.o
