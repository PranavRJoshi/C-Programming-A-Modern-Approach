all: project_4 

project_4: project_4.o readline.o 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o project_4 project_4.o readline.o 

project_4.o: project_4.c readline.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c project_4.c 

readline.o: readline.c readline.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c readline.c 

clean:
	rm project_4 project_4.o readline.o 
