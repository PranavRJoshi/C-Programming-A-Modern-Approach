// Q. (a) Show how to declare a tag named complex for a structure with two members, real and imaginary, of type double.
//    (b) Use the complex tag to declare variables named c1, c2, and c3.
//    (c) Write a function named make_complex that stores its two arguments (both of type double) in a complex structure, then returns the structure.
//    (d) Write a function named add_complex that adds the corresponding members of its arguments (both complex structures), then returns the result (another complex structure).

#include <stdio.h>

/*
 * complex: a structure that contains two members--real and imaginary--which acts 
 *          as a data type that is capable to store a "complex" number
*/
struct complex {
  double real;
  double imaginary;
};

/*
 * make_complex:  takes two double arguments--real and imaginary--and 
 *                returns a structure tag type of complex
*/
struct complex make_complex (double real, double imaginary);

/*
 * add_complex: takes two complex structure arguments and adds their corresponding
 *              members into a third structure, which is returned.
*/
struct complex add_complex (struct complex complex_1, struct complex complex_2);

int main (void) {
  
  struct complex c1, c2, c3;

  c1.real       = 1.0;
  c1.imaginary  = 0.0;

  c2 = make_complex(0.0, 1.0);

  c3 = add_complex(c1, c2);

  printf("[LOG] c1 has the values for members real and imaginary as %g and %g respectively.\n", c1.real, c1.imaginary);
  printf("[LOG] c2 has the values for members real and imaginary as %g and %g respectively.\n", c2.real, c2.imaginary);
  printf("[LOG] c3 has the values for members real and imaginary as %g and %g respectively.\n", c3.real, c3.imaginary);

  return 0;
}

struct complex make_complex (double r, double i) {
  struct complex temp;

  temp.real       = r;
  temp.imaginary  = i;

  return temp;
}

struct complex add_complex (struct complex c1, struct complex c2) {
  struct complex temp;

  temp.real       = c1.real       + c2.real;
  temp.imaginary  = c1.imaginary  + c2.imaginary;

  return temp;
}

