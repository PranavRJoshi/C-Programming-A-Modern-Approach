CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=project_1
OBJS=stackADT.o project_1.o

all: project_1

project_1: project_1.o stackADT.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT.o: stackADT.c stackADT.h
	$(CC) $(CFLAGS) -c $<
 
project_1.o: project_1.c stackADT.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)

