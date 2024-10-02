// Q. Write the following parameterized macros.
//    a. CHECK(x, y, n) - Has the value 1 if both x and y fall between 0 and n - 1, inclusive.
//    b. MEDIAN(x, y, z) - Finds the median of x, y, and z.
//    c. POLYNOMIAL(x) - Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

#include <stdio.h>

#define CHECK(x, y, n)          \
(((x) >= 0 && (x) <= ((n) - 1)) ? ((y) >= 0 && (y) <= ((n) - 1)) ? 1 : 0 : 0)

#define MEDIAN(x, y, z)         \
((x) <= (y) ? ((y) <= (z) ? y : (x) <= (z) ? z : x) : ((z) <= (y) ? y : (x) <= (z) ? x : z))

#define POLYNOMIAL(x)           \
((3 * (x) * (x) * (x) * (x) * (x)) + (2 * (x) * (x) * (x) * (x)) - (5 * (x) * (x) * (x)) - ((x) * (x)) + (7 * (x)) - 6)

int main (void) {

  int check_result = 0;
  int median_result = 0;
  int polynomial_result = 0;

  check_result = CHECK(10, 29, 30);
  median_result = MEDIAN(9, 11, 10);
  polynomial_result = POLYNOMIAL(5);

  printf("The result obtained from invoking CHECK is: %d\n", check_result);
  printf("The result obtained from invoking MEDIAN is: %d\n", median_result);
  printf("The result obtained from invoking POLYNOMIAL is: %d\n", polynomial_result);

  return 0;
}
