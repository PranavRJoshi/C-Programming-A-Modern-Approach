// Q. Modify the sum2.c program of Section 7.1 to sum a series of double values.

#include <stdio.h>

int main (void) {

  double n, sum = 0;

  printf("This program sums a series of integers.\n");
  printf("Enter integers (0 to terminate): ");
  scanf("%lf", &n);

  // by default, the compiler will treat 0.0 as a double constant, so no need to append any character when it comes to double
  // to force the compiler to treat it as a floating-point constant, append the character f or F at the end, like 0.0f or 0.0F
  // to force the compiler to treate it as a long double, append the character l ("ell") or L at the end, like 0.0l or 0.0L
  while (n != 0.0) {
    sum += n;
    scanf("%lf", &n);
  }

  printf("The sum is: %lf\n", sum);
  

  return 0;
}
