// Q. The power function of Section 9.6 can be made faster by having it calculate x^n in a different way. We first notice that if n is a power of 2, then x^n can be computed by squaring. For example, x^4 is the square of x^2, so x^4 can be computed using only two multiplication instead of three. As it happens, this technique can be used even when n is not a power of 2. If n is even, we use the formula x^n = (x^n/2)^2. If n is odd, then x^n = x * x^n-1. We write a recursive function that computes x^n. (The recursion ends when n = 0, in which case the function returns 1.) To test your function, write a program that asks the user to enter values for x and n, calls power to compute x^n, and then displays the value returned by the function.

#include <stdio.h>

int power (int number, int power);

int main (void) {

  int num, pow;
  num = 1;
  pow = 0;

  int result = 0;

  printf("Enter the number and the power to which it will be raised: ");
  scanf("%d%d", &num, &pow);

  result = power(num, pow);

  printf("%d raised to power %d is: %d\n", num, pow, result);

  return 0;
}

int power (int x, int n) {
  if (n == 0) {
    return 1;
  }

  if (n % 2 == 0){
    return power(x, n / 2) * power(x, n / 2);
  } else {
    return x * power(x, n - 1);
  }
}

