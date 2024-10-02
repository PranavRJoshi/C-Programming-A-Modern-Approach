// Q. a. Write a complete description of the type of the function f, assuming that it's declared as follows:
//        int (*f(float (*) (long), char *)) (double);
//    b. Give an exmple showing how f would be called.
// A. f is a function which takes in two parameters: 
//      1. a pointer to a function which takes in a long as an argument and returns a float
//      2. a pointer to char
//    and returns a pointer to a functions which has an argument of type double and returns an integer.

#include <stdio.h>

float convert_long (long num);
int convert_double (double num);
int (*f (float (*pf) (long convert_to_float), char *test)) (double convert_to_int);

int main (void) {

  int (*ret_ptr_to_fcn) (double);
  ret_ptr_to_fcn = f(convert_long, "Hello, World!");

  int convert_to_int = (*ret_ptr_to_fcn)(10.0);

  printf("The value obtained from convert_to_int is: %d\n", convert_to_int);

  return 0;
}

float convert_long (long num) {
  return ((float) num);
}

int convert_double (double num) {
  return ((int) num);
}

int (*f (float (*pf) (long convert_to_float), char *test)) (double convert_to_float) {

  printf("\n\n*** Calling from %s function ***\n\n", __func__);

  float f_test = pf(5);

  printf("The result of calling convert_long with 5 as argument is: %f\n", f_test);
  printf("The provided string is: %s\n", test);

  printf("\n\n*** End of Calling from %s function ***\n\n", __func__);

  return convert_double;
}

