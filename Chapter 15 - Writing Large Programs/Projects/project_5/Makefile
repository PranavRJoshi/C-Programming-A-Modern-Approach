all: project_5 

project_5: project_5.o stack.o 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o project_5 project_5.o stack.o

project_5.o: project_5.c stack.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c project_5.c 

stack.o: stack.c stack.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c stack.c 

clean:
	rm project_5 project_5.o stack.o 
