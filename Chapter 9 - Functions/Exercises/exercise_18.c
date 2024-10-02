// Q. Write a recursive version of the gcd function (see Exercise 3). Here's the strategy to use for computing gcd(m, n): If n is 0, return m. Otherwise, call gcd recursively, passing n as the first argument and m % n as the second.

#include <stdio.h>

int gcd (int num_1, int num_2);

int main (void) {
  
  int num_1, num_2;
  int gcd_value;

  printf("Enter two numbers: ");
  scanf("%d%d", &num_1, &num_2);

  gcd_value = gcd(num_1, num_2);

  printf("The greatest common divisor of %d and %d is: %d\n", num_1, num_2, gcd_value);

  return 0;
}

int gcd (int m, int n) {
  if (n == 0) {
    return m;
  }

  return gcd(n, m % n);
}
