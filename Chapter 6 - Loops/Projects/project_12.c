// Q. Modify Programming Project 11 so that the program continues adding terms until the current term becomes less than e, where e is a small (floating-point) number entered by the user.

#include <stdio.h>

int main (void) {

  float value_of_e = 1.00f;
  float factorial_value = 1.00f;
  float e, current_term = 1.00f;
  int count = 0;

  printf("Enter the value of e: ");
  scanf("%f", &e);

  while (current_term > e) {
    for (int j = 1; j <= count + 1; j++)
      factorial_value *= j;

    current_term = 1.00f / factorial_value;

    value_of_e += current_term;
    factorial_value = 1.00f;
    count += 1;
  }

  printf("The current term (term number: %d) has the value %f which is less than the given value.\n", count, current_term);
  printf("The value of e for the given value of n is: %f\n", value_of_e);

  return 0;  
}


