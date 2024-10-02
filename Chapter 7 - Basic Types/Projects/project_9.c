// Q. Write a program that asks the user for a 12-hour time, then displays the time in 24-hour form:
//    Enter a 12-hour time: 9:11 PM
//    Equivalent 24-hour time: 21:11
// See Programming Project 8 for a description of the input format.

#include <stdio.h>

int main (void) {

  int hour, minute;
  char ch;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &minute, &ch);

  if (ch == 'p' || ch == 'P') {
    hour += 12;
    if (hour == 24)
      hour = 12;
  }
  
  printf("Equivalent 24-hour time: %d:%d\n", hour, minute);

  return 0;
}

