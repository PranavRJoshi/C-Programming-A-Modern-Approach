// Q. Modify Programming Project 3 from Chapter 6 so that it includes the following function:
//    void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
// numerator and denominator are the numerator and denominator of a fraction. reduced_numerator and reduced_denominator are pointers to variables in which the function will store the numerator and denominator of the fraction once it has been reduced to lowest terms.

#include <stdio.h>

void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main (void) {

  int num, denom;
  int red_num, red_denom;

  printf("Enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  reduce (num, denom, &red_num, &red_denom);

  printf("The reduced fraction is: %d/%d\n", red_num, red_denom);

  return 0;
}

void reduce (int n, int d, int *rn, int *rd) {
  int remainder;
  int temp_num, temp_denom;

  temp_num = n, temp_denom = d;

  // compute the GCD, which is divides the numerator and denominator to get the reduced fraction
  // the GCD is stored in temp_num
  while (temp_denom != 0) {
    remainder = temp_num % temp_denom;
    temp_num = temp_denom;
    temp_denom = remainder;
  }

  *rn = n / temp_num;
  *rd = d / temp_num;
}

