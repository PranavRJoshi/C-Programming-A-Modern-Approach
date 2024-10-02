// Q. Write a function digit(n, k) that returns the kth digit (from the right) in n (a positive integer). For example, digit(829, 1) returns 9, and digit(829, 2) returns 2, and digit(829, 3) returns 8. If k is greater than the number of digits in n, have the function return 0.

#include <stdio.h>

int digit (int num, int location);

int main (void) {

  int num;
  int k = 0;
  int fetched_digit = 0;

  printf("Enter a number: ");
  scanf("%d", &num);

  printf("Enter the location from the right of the number to extract the digit: ");
  scanf("%d", &k);

  fetched_digit = digit(num, k);

  printf("The corresponding digit is: %d\n", fetched_digit);

  return 0;
}

int digit (int n, int k) {
  int count = 0;
  int digit = 0;

  while (count != k) {
    if (n < 0) {
      digit = 0;
      break;
    }

    digit = n % 10;
    n /= 10;
    count++;
  }
  
  return digit;
}

