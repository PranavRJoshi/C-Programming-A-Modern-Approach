// Q. Our first array program prompts the user to enter a series of numbers, then writes the number in reverse order:
//    Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31
//    In reverse order: 31 50 11 23 94 7 102 49 82 34
// Our strategy will be to store the numbers in an array as they're read, then go through the array backwards, printing the elements one by one. In other words, we won't actually reverse the elements in the array, but we'll make the user think we did.

#include <stdio.h>

#define N 10

int main (void) {

  int num[N];

  printf("Enter 10 numbers: ");

  // initializing i inside the for loop is a feature that was added in C99
  // so this code won't work as intented if compiled for C89
  for (int i = 0; i < N; i++) {
    scanf("%d", &num[i]);  
  }

  printf("In reverse order: ");

  for (int i = N - 1; i >= 0; i--) {
    printf("%d ", num[i]);
  }

  printf("\n");

  return 0;  
}

