all: project_2

project_2: project_2.o line.o word.o 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o project_2 project_2.o line.o word.o

project_2.o: project_2.c word.h line.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c project_2.c

line.o: line.c line.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c line.c 

word.o: word.c word.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c word.c 

clean:
	rm project_2 project_2.o line.o word.o
