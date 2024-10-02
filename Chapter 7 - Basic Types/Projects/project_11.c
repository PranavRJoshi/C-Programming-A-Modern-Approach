// Q. Write a program that takes a first name and last name entered by the user and displays the last name, a comma, and the first initial, followed by a period.
//    Enter a first and last name: Lloyd Fosdick
//    Fosdick, L.
// The user's input may contain extra spaces before the first name, between the first and last names, and after the last name.

#include <stdio.h>

int main (void) {

  char first_initial, ch;

  printf("Enter a first and last name: ");
  first_initial = getchar();

  while ((ch = getchar()) != '\x20');   // hex character escape for space

  while ((ch = getchar()) == '\x20');

  // we need to use do while instead of while loop since the upper while loop to check for white spaces goes like this:
  // the loop persists while the ch is a space
  // when it encounters a non-space character, the loop terminates
  // and the non-character is stored in ch, which needs to be displayed as output
  do {
    putchar(ch);
  } while ((ch = getchar()) != '\n');

  putchar(',');
  putchar(' ');
  putchar(first_initial);
  putchar('.');
  putchar('\n');

  return 0;
}

