CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=stackADT
OBJS=stackADT.o stackclient.o

all: stackADT

stackADT: stackADT.o stackclient.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT.o: stackADT.c stackADT.h
	$(CC) $(CFLAGS) -c $<
 
stackclient.o: stackclient.c stackADT.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)
