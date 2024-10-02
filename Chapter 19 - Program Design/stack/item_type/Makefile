CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=stackADT2
OBJS=stackADT2.o stackclient2.o

all: stackADT2

stackADT2: stackADT2.o stackclient2.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT2.o: stackADT2.c stackADT2.h
	$(CC) $(CFLAGS) -c $<

stackclient2.o: stackclient2.c stackADT2.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)
