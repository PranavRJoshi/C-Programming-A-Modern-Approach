// Q. Write a function that computes the value of the following polynomial:
//    3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
// Write a program that asks the user to enter a value of x, calls the function to compute the value of polynomial, and then displays the value returned by the function.

#include <stdio.h>

double calculate_polynomial (double x);

int main (void) {
  
  double x = 0.0;
  double result = 0.0;

  printf("Enter the value for x: ");
  scanf("%lf", &x);

  result = calculate_polynomial(x);

  printf("The result of expression 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 with x = %.2lf is: %.2lf\n", x, result);

  return 0;
}

double calculate_polynomial (double x) {
  double fifth_power = x * x * x * x * x;
  double fourth_power = x * x * x * x;
  double third_power = x * x * x;
  double second_power = x * x;
  double first_power = x;

  return (3 * fifth_power) + (2 * fourth_power) - (5 * third_power) - second_power + (7 * first_power) - 6;
}

