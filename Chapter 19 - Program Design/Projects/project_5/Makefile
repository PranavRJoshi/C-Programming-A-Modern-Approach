CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address

EXEC=project_5
OBJS=project_5.o queueADT.o

all: project_5

project_5: project_5.o queueADT.o
	$(CC) $(CFLAGS) -o $@ $^

project_5.o: project_5.c queueADT.h
	$(CC) $(CFLAGS) -c $<

queueADT.o: queueADT.c queueADT.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXEC) $(OBJS)

