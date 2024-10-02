CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99

all: main

main: main.o singly_linked_list.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c singly_linked_list.h
	$(CC) $(CFLAGS) -c $<

singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm main.o singly_linked_list.o main
