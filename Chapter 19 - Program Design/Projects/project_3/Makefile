CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=project_3
OBJS=stackADT4.o project_3.o

all: project_3

project_3: stackADT4.o project_3.o
	$(CC) $(CFLAGS) -o $@ $^

stackADT4.o: stackADT4.c stackADT4.h
	$(CC) $(CFLAGS) -c $<

project_3.o: project_3.c stackADT4.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)
