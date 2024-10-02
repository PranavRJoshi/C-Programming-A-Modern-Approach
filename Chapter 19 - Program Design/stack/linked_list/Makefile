CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=stackADT4
OBJS=stackADT4.o stackclient4.o

all: stackADT4

stackADT4: stackADT4.o stackclient4.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT4.o: stackADT4.c stackADT4.h
	$(CC) $(CFLAGS) -c $<

stackclient4.o: stackclient4.c stackADT4.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)
