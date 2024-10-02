CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=project_4
OBJS=project_4.o stackADT.o stackADT4.o

all: project_4

project_4: project_4.o stackADT.o stackADT4.o
	$(CC) $(CFLAGS) -o $@ $^

project_4.o: project_4.c stackADT.h stackADT4.h
	$(CC) $(CFLAGS) -c $<

stackADT.o: stackADT.c stackADT.h
	$(CC) $(CFLAGS) -c $<

stackADT4.o: stackADT4.c stackADT4.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)
