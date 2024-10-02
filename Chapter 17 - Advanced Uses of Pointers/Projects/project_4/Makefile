all: project_4

project_4: project_4.o word.o line.o
	gcc -o project_4 project_4.o word.o line.o 

project_4.o: project_4.c word.h line.h 
	gcc -c project_4.c 

word.o: word.c word.h 
	gcc -c word.c 

line.o: line.c line.h 
	gcc -c line.c

clean: 
	rm project_4 project_4.o word.o line.o 
