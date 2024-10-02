all: project_1 

project_1: project_1.o line.o word.o 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o project_1 project_1.o line.o word.o

project_1.o: project_1.c word.h line.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c project_1.c

line.o: line.c line.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c line.c 

word.o: word.c word.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c word.c 

clean:
	rm project_1 project_1.o line.o word.o
