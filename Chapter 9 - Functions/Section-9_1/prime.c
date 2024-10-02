// Q. When given a number n, the is_prime function will divide n by each of the numbers between 2 and the square root of n; if the remainder is ever 0, we know that n isn't prime.

#include <stdio.h>

#define true 1
#define false 0

_Bool is_prime (int n) {

  if (n <= 1) {
    return false;
  }

  for (int i = 2; i * i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main (void) {

  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (is_prime(n)) {
    printf("Prime\n");
  } else {
    printf("Not prime\n");
  }

  return 0;
}

