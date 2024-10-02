// Q. Write a program that asks the user to enter a fraction, then reduces the fraction to lowest terms:
//  Enter a fraction: 6/12
//  In lowest terms: 1/2
// Hint: To reduce a fraction to lowest terms, first compute the GCD of numerator and denominator. Then divide both the numerator and denominator by the GCD.

#include <stdio.h>

int main (void) {

  int numerator, denominator;
  int remainder;

  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  // define the value of m and n, which will be used to compute the value of GCD
  int m = numerator, n = denominator;

  // Compute the GCD, which is stored in the variable m
  while (n != 0) {
    remainder = m % n;
    m = n;
    n = remainder;
  }

  printf("In lowest terms: %d/%d\n", numerator / m, denominator / m);

  return 0;
}

