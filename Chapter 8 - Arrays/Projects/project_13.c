// Q. Modify Programming Project 11 from Chapter 7 so that the program labels its output:
//    Enter a first and last name: Lloyd Fosdick
//    You entered the name: Fosdick, L.
// The program will need to store the last name (but not the first name) in an array of characters until it can be printed. You may assume that the last name is no more than 20 characters long.

#include <stdio.h>

#define LAST_NAME_SIZE 20

int main (void) {

  char ch;
  char first_initial;
  char last_name[LAST_NAME_SIZE];
  int i;

  printf("Enter a first and last name: ");

  // store the first name's initial as it is needed later
  first_initial = getchar();

  // this loop acts as a null statement that loops till ch has the value of a space (' ')
  while (getchar() != ' ');

  // loop till the new-line character is encountered and simultaneously increment i and use it as an index.
  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    last_name[i] = ch;
  }

  // print out the last name first
  for (int j = 0; j < i; j++) {
    printf("%c", last_name[j]);
  }

  // add comma, the first name's initial, and a period
  printf(", %c.\n", first_initial);

  return 0;
}

