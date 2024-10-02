all: project_3 

project_3: project_3.o quicksort.o 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o project_3 project_3.o quicksort.o 

project_3.o: project_3.c quicksort.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c project_3.c 

quicksort.o: quicksort.c quicksort.h 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -c quicksort.c 

clean: 
	rm project_3 project_3.o quicksort.o 
