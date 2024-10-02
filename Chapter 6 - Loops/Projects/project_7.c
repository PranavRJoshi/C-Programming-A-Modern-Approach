// Q. Rearrange the square3.c program so that the for loop initializes i, tests i, and increments i. Don't rewrite the program; in particular, don't use any multiplications.

#include <stdio.h>

int main (void) {

  int i, n, square = 0;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++)
      square += i;
    printf("%10d%10d\n", i, square);
    square = 0;
  }

  return 0;
}

