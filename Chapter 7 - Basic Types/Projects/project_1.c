// Q. The square2.c program of Section 6.3 will fail (usually by printing strange answers) if i * i exceeds the maximum int value. Run the program and determine the smallest value of n that causes failure. Try changing the type of i to short and running the program again. (Don't forget to update the conversion specifications in the call of printf!) Then try long. From these experiments, what can you conclude about the number of bits used to store integer types on your machine?
//
// For int variable:
// 999289 2146092849 (max value representation)
// 999290 -2146875868 (the strange answer)
// For short variable:
// 181     32761  (max value representation)
// 182    -32412  (the strange answer)
// For long variable:
// I'm not gonna bother waiting minutes to get a validation that my machine is a 64-bit one.

#include <stdio.h>

int main (void) {

  long i, n;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in the table: ");
  scanf("%ld", &n);

  for (i = 1; i <= n; i++) {
    printf("%10ld%10ld\n", i, i*i);
  }

  return 0;
}

