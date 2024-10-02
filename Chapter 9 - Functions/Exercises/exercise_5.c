// Q. Write a function num_digits(n) that returns the number of digits in n (a positive integer). Hint: To determine the number of digits in a number n, divide it by 10 repeatedly. When n reaches 0, the number of divisions indicates how many digits n originally had.

#include <stdio.h>

int num_digits (int num);

int main (void) {

  int n;
  int digit_count = 0;

  printf("Enter a number to check it's digit (a positive integer): ");
  scanf("%d", &n);

  digit_count = num_digits(n);

  printf("%d has %d digits.\n", n, digit_count);
  
  return 0;
}

int num_digits (int n) {
  int count = 0;
  
  while (n > 0) {
    n /= 10;
    count++;
  }

  return count;

}

