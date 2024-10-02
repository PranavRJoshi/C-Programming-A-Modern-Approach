// Q. Modify the repdigit.c program of Section 8.1 so that it shows which digits (if any) were repeated:
//    Enter a number: 939577
//    Repeated digits: 7 9

#include <stdio.h>
#include <stdbool.h>

int main (void) {

  int digit;
  long n;
  bool digit_seen[10] = {false};
  bool repeated_digits[10] = {false};
  bool has_repeated_digit = false;

  printf("Enter a number: ");
  scanf("%ld", &n);

  // loop through the number n, and check the individual digits to check if the digit has repeated
  // if the digit is seen and repeats, it is tracked in repeated_digits array and turns the has_repeated_digits flags on.
  while (n != 0) {
    digit = n % 10;
    n /= 10;
    if (digit_seen[digit] == false) {
      digit_seen[digit] = true;
    } else {
      has_repeated_digit = true;
      repeated_digits[digit] = true;
    }
  }

  // check if the digits has repeated, the if statement is executed, else jumps to the else clause
  // if the digits are repeated, it loops through the repeated_digits array
  // if the element of repeated_digits array is true, the index of the array is printed indicating the number that was repeated.
  if (has_repeated_digit) {
    printf("Repeated digits: ");
    for (int i = 0; i < ((int) (sizeof(repeated_digits) / sizeof(repeated_digits[0]))); i++) {
      if (repeated_digits[i] == true) {
        printf("%d ", i);
      }
    }
    printf("\n");
  } else {
    printf("No repeated digit\n");
  }

  return 0;  
}

