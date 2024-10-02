// Q. Which of the following are not legal constants in C? Classify each legal constants as either integer or floating-point.
//    a. 010E2
//    b. 32.1E+5
//    c. 0790
//    d. 100_000
//    e. 3.978e-2
// Expectation:
//    a. 010E2 seems invalid since the preceding zero indicates that the number is an octal number while the E2 represents the number is a floating point (the decimal point is optional in floating-point). 
//    b. 32.1E+5 seems valid and it represents a floating-point number.
//    c. 0790 seems like a valid octal number (integer). (I forgot that 9 is not an valid octal number) 
//    d. 100_000 seems like a valid integer number (?). This is an assumption since I think _ is used like a placeholder to make number readability easier and does not have any affect on the numeric value of the number.
//    e. 3.978e-2 seems like a valid floating-point number.
// Actual:
//    a, b and e are valid floating-point but c and d are not valid integer numbers. (or any valid constant)

#include <stdio.h>

int main (void) {

  printf("010E2 is %f\n", 010E2);
  printf("32.1E+5 is %f\n", 32.1E+5);
  // printf("0790 is %d\n", 0790);         // invalid since 9 is not a valid number
  // printf("100_000 is %d\n", 100_000);   // invalid since _000 is an invalid suffix on integer constant
  printf("3.978e-2 is %f\n", 3.978e-2);

  return 0;
}

