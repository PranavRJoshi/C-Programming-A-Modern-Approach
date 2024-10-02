// Q. Modify the reverse.c program of Section 8.1 to use the expression (int) (sizeof(a) / sizeof(a[0])) (or a macro with this value) for the array length

#include <stdio.h>

#define N 10
#define SIZE (int) (sizeof(num) / sizeof(num[0]))

int main (void) {

  int num[N] = {0};

  printf("Enter 10 numbers: ");

  // initializing i inside the for loop is a feature that was added in C99
  // so this code won't work as intented if compiled for C89
  for (int i = 0; i < SIZE; i++) {
    scanf("%d", &num[i]);  
  }

  printf("In reverse order: ");

  for (int i = SIZE - 1; i >= 0; i--) {
    printf("%d ", num[i]);
  }

  printf("\n");

  return 0;  
}


