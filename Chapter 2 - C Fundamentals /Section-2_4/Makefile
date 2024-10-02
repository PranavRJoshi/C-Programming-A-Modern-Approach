all: d_weight d_weight_revised

d_weight: 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o d_weight dimensional_weight.c

d_weight_revised: 
	gcc -O -Wall -W -pedantic -ansi -std=c99 -o d_weight_revised dimensional_weight_revisited.c

clean:
	rm d_weight && rm d_weight_revised