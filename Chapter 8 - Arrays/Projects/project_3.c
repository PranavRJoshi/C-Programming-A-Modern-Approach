// Q. Modify the repdigit.c program of Section 8.1 so that the user can enter more than one number to be tested for repeated digits. The program should terminate when the user enters a number that's less than or equal to 0.

#include <stdio.h>

int main (void) {

  long n, temp;
  int digit;
  int digit_count[10] = {0};

  for (;;) {
    printf("Enter a number: ");
    scanf("%ld", &n);

    // if the number is less than or equal to 0, terminate the program
    if (n <= 0)
      break;

    // clearing the digit_count array
    for (int i = 0; i < 10; i++) {
      digit_count[i] = 0;
    }

    temp = n;

    // count the digits' occurances in the given number
    while (temp != 0) {
      digit = temp % 10;
      temp /= 10;
      digit_count[digit] += 1;
    }

    printf("For number: %ld\n", n);
    printf("Digits:      ");
    for (int i = 0; i < 10; i++) {
      printf("%3d ", i);
    }

    printf("\nOccurances:  ");
    for(int i = 0; i < 10; i++) {
      printf("%3d ", digit_count[i]);
    }
    printf("\n");
  }

  return 0;
}

