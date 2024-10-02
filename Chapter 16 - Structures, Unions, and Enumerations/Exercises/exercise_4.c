// Q. Repeat Exercise 3, but this time using a type named Complex.

#include <stdio.h>

/*
 * Complex: a structure that contains two members--real and imaginary--which acts 
 *          as a data type that is capable to store a "complex" number
*/
typedef struct {
  double real;
  double imaginary;
} Complex;

/*
 * make_complex:  takes two double arguments--real and imaginary--and 
 *                returns a structure tag type of complex
*/
Complex make_complex (double real, double imaginary);

/*
 * add_complex: takes two complex structure arguments and adds their corresponding
 *              members into a third structure, which is returned.
*/
Complex add_complex (Complex complex_1, Complex complex_2);

int main (void) {
  
  Complex c1, c2, c3;

  c1.real       = 1.0;
  c1.imaginary  = 0.0;

  c2 = make_complex(0.0, 1.0);

  c3 = add_complex(c1, c2);

  printf("[LOG] c1 has the values for members real and imaginary as %g and %g respectively.\n", c1.real, c1.imaginary);
  printf("[LOG] c2 has the values for members real and imaginary as %g and %g respectively.\n", c2.real, c2.imaginary);
  printf("[LOG] c3 has the values for members real and imaginary as %g and %g respectively.\n", c3.real, c3.imaginary);

  return 0;
}

Complex make_complex (double r, double i) {
  Complex temp;

  temp.real       = r;
  temp.imaginary  = i;

  return temp;
}

Complex add_complex (Complex c1, Complex c2) {
  Complex temp;

  temp.real       = c1.real       + c2.real;
  temp.imaginary  = c1.imaginary  + c2.imaginary;

  return temp;
}

