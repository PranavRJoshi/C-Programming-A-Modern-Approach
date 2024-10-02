// Q. a. Write a macro DISP(f, x) that expands into a call of printf that displays the value of the function f when called with argument x. For example,
//    DISP(sqrt, 3.0);
// should expand into
//    printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0);
//    
//    b. Write a macro DISP2(f, x, y) that's similar to DISP but works for functions with two arguments.

#include <stdio.h>
#include <math.h>

#define DISP(f, x)                  \
printf(#f "(%g) = %g\n", x, f(x))

// undefining the isgreater macro which is defined in the math.h header, and defining my own
// #undef isgreater
// #define isgreater(x, y)             \
// ((x) > (y) ? (x) : (y))

#define DISP2(f, x, y)              \
printf("Calling " #f ", the division of %Lf and %Lf has the remainder: %Lf\n", x, y, f(x, y))

int main (void) {

  DISP(sqrt, 25.0);

  // the l at the end of the constant informs the compiler that the constant is of type long double
  // if we remove the decimal point, the number is instead treated as a long integer
  DISP2(fmodl, 12.5l, 4.5l);

  return 0;
}

