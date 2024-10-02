// Q. Modify Programming Project 4 from Chapter 7 so that the program labels its output:
//    Enter phone number: 1-800-COL-LECT
//    In numeric form: 1-800-265-5328
// The program will need to store the phone number (either in its original form or in its numeric form) in an array of characters until it can be printed. You may assume that the phone number is no more than 15 characters long.

#include <stdio.h>
#include <ctype.h>

#define NUM_LENGTH 15

int main (void) {

  // store the original number entered by the user
  char original_number[NUM_LENGTH];
  // store the numeric from of the number
  char numeric_number[NUM_LENGTH];
  // store the characters that are entered by the user
  char ch;
  // keep track of the number of characters entered by the user
  int i;

  printf("Enter phone number: ");

  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    original_number[i] = ch;
    switch(toupper(ch)) {
      case 'A': case 'B': case 'C':
        numeric_number[i] = '2';
        break;
      case 'D': case 'E': case 'F':
        numeric_number[i] = '3';
        break;
      case 'G': case 'H': case 'I':
        numeric_number[i] = '4';
        break;
      case 'J': case 'K': case 'L':
        numeric_number[i] = '5';
        break;
      case 'M': case 'N': case 'O':
        numeric_number[i] = '6';
        break;
      case 'P': case 'Q': case 'R': case 'S':
        numeric_number[i] = '7';
        break;
      case 'T': case 'U': case 'V':
        numeric_number[i] = '8';
        break;
      case 'W': case 'X': case 'Y': case 'Z':
        numeric_number[i] = '9';
        break;
      default:
        numeric_number[i] = ch;
    }
  }

  printf("The original number entered is: ");
  for (int j = 0; j < i; j++) {
    printf("%c", original_number[j]);
  }
  
  printf("\n");

  printf("The numeric form is: ");
  for (int j = 0; j < i; j++) {
    printf("%c", numeric_number[j]);
  }

  printf("\n");

  return 0;
}

