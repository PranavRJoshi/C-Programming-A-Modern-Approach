// Q. Simplify Programming Project 1 (b) by taking advantage of the fact that an array name can be used as a pointer.

#include <stdio.h>

#define MSG_SIZE 50

int main (void) {

  char message[MSG_SIZE];
  char ch;
  int message_count = 0;

  printf("Enter a message: ");
  ch = getchar();

  while (ch != '\n' && message_count <= MSG_SIZE) {
    *(message+message_count) = ch;
    message_count++;
    ch = getchar();
  }

  printf("Reversal is: ");

  while (message_count >= 0) {
    putchar(*(message + (--message_count)));
  }

  printf("\n");

  return 0;
}

