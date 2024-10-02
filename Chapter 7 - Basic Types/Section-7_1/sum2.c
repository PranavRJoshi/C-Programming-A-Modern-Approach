// One problem with this [sum.c from Section 6.1] program is that the sum (or one of the input numbers might exceed the largest value allowed for an int variable. For instance, when the program is run on a machine whose integers are 16 bits long:
//    This program sums a series of integers.
//    Enter integers (0 to terminate): 10000 20000 30000 0
//    The sum is: -5536
// The sum was 60000, which wouldn't fit in an int variable, so overflow occurred. When overflow occurs with signed numbers, the outcome is undefined. In this case, we got an apparently meaningless number. To improve the program, let's switch to long variables 

/* Sums a series of numbers (using long variables) */

#include <stdio.h>

int main (void) {
  
  long n, sum = 0;

  printf("This program sums a series of integers.\n");
  printf("Enter integers (0 to terminate): ");
  scanf("%ld", &n);

  while (n != 0) {
    sum += n;
    scanf("%ld", &n);
  }

  printf("The sum is: %ld\n", sum);

  return 0;  
}

