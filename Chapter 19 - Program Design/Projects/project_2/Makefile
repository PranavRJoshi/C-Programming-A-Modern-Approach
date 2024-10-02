CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=project_2
OBJS=stackADT.o project_2.o

all: project_2

project_2: project_2.o stackADT.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT.o: stackADT.c stackADT.h
	$(CC) $(CFLAGS) -c $<
 
project_2.o: project_2.c stackADT.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)

