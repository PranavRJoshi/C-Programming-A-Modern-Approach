CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
MEM_LEAK=-fsanitize=address
DEBUGFLAGS=-g
PREPROCESSFLAGS=-e

EXECUTABLE=main
OBJS=main.o static_var.o extern_var.o extern_utils.o pointer_fiesta.o

all: main

main: main.o static_var.o extern_var.o extern_utils.o pointer_fiesta.o
	$(CC) $(CFLAGS) $(MEM_LEAK) -o $@ $^

main.o: main.c static_var.h extern_var.h
	$(CC) $(CFLAGS) -c $<

static_var.o: static_var.c static_var.h
	$(CC) $(CFLAGS) -c $<

extern_var.o: extern_var.c extern_var.h extern_utils.h pointer_fiesta.h
	$(CC) $(CFLAGS) -c $<

extern_utils.o: extern_utils.c extern_utils.h
	$(CC) $(CFLAGS) -c $<

pointer_fiesta.o: pointer_fiesta.c pointer_fiesta.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(EXECUTABLE) $(OBJS)
