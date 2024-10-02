// Q, The value of the mathematical constant e can be expressed as an infinite series:
// e = 1 + 1/1! + 1/2! + 1/3! + ...
// Write a program that approximates e by computing the value of 
// e = 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
// where n is an integer entered by the user.

#include <stdio.h>

int main (void) {

  int n;
  float value_of_e = 1.00f;
  float factorial_value = 1.00f;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
      factorial_value *= j;

    value_of_e += (1.00f / factorial_value);
    factorial_value = 1.00f;
  }

  printf("The value of e for the given value of n is: %f\n", value_of_e);

  return 0;  
}

