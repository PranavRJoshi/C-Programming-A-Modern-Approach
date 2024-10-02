// Q. The reverse.c program of Section 8.1 reads 10 numbers, then writes the numbers in reverse order. As the program reads the numbers, it stores them in an array. Once all the numbers are read, the program steps through the array backwards as it prints the numbers.
// The original program used subscripting to access elements of the array. Here's a new version in which I've replaced subscripting with pointer arithmetic.

#include <stdio.h>

#define N 10

int main (void) {

  int num[N];
  int *p;

  printf("Enter 10 numbers: ");

  for (p = num; p < num + N; p++) {
    scanf("%d", p);
  }

  printf("In reverse order: ");

  for (p = num + (N - 1); p >= num; p--) {
    printf("%d ", *p);
  }

  printf("\n");

  return 0;  
}

