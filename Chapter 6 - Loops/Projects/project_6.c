// Q. Write a program that prompts the user to enter a number n, then printts all even squares between 1 and n. For example, if the user enters 100, the program should print the following:
//    4
//    16
//    36
//    64
//    100

#include <stdio.h>

int main (void) {

  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 2; i * i <= n; i += 2) {
    printf("%d squared = %d\n", i, i * i);
  }

  return 0;
}

