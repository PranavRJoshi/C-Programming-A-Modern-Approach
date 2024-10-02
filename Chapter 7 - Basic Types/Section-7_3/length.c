// A program that calculates the length of a message. After the user enters the message, the program displays the length:
//    Enter a messsage: Brevity is the soul of wit.
//    Your message was 27 character(s) long.
// The length includes spaces and punctuation, but not the new-line character at the end of the message.

#include <stdio.h>

int main (void) {

  int length = 0;
  
  printf("Enter a message: ");

  while (getchar() != '\n')
    length += 1;

  printf("Your message was %d character(s) long.", length);

  return 0;  
}

