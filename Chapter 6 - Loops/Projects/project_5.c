// Q. Progamming Project 1 in Chapter 4 asked you to write a program that displays a two-digit number with its digits reversed. Generalize the program so that the number can have one, two, three, or more digits. Hint: Use a do loop that repeatedly divides the number by 10, stopping when it reaches 0.

#include <stdio.h>

int main (void) {

  int num;
  int reverse_num = 0;

  printf("Enter a number: ");
  scanf("%d", &num);
  
  do {
    reverse_num = reverse_num * 10 + num % 10;
    num /= 10;
  } while (num != 0);

  printf("The reverse of the entered number is: %d\n", reverse_num);
  
  return 0;
}

