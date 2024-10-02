CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=stackADT3
OBJS=stackADT3.o stackclient3.o

all: stackADT3

stackADT3: stackADT3.o stackclient3.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT3.o: stackADT3.c stackADT3.h
	$(CC) $(CFLAGS) -c $<

stackclient3.o: stackclient3.c stackADT3.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)
