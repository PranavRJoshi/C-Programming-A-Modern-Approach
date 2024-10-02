// Q. Write a function gcd(m, n) that calculates the greatest common divisor of the integers m and n. (Programming Project 2 in Chapter 6 describes Euclid's algorithm for computing the GCD.)

#include <stdio.h>

int gcd (int m, int n);

int main (void) {

  int n, m;

  printf("Enter two integers: ");
  scanf("%d%d", &m, &n);

  printf("Greatest common divisor: %d\n", gcd(m, n));

  return 0;
}

int gcd (int num_1, int num_2) {
  
  int remainder;

  while (num_2 != 0) {
    remainder = num_1 % num_2;
    num_1 = num_2;
    num_2 = remainder;
  }

  return num_1;
}

