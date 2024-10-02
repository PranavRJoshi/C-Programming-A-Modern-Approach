// Q. 1a. Write a program that reads a message, then prints the reversal of the message:
//    Enter a message: Don't get mad, get even.
//    Reversal is: .nevn teg ,dam teg t'noD
// Hint: Read the message one character at a time (using getchar) and store the characters in an array. Stop reading when the array is full or the character read is '\n'.
//    1b. Revise the program to use a pointer instead of an integer to keep track of the current position in the array.

#include <stdio.h>

#define MSG_SIZE 50

int main (void) {

  char message[MSG_SIZE];
  char *msg_ptr = message;
  int message_count = 0;

  printf("Enter a message: ");
  *msg_ptr = getchar();
  message_count++;

  while ((*(msg_ptr+message_count) = getchar()) != '\n' && message_count <= MSG_SIZE) {
    message_count++;
  }

  printf("Reversal is: ");

  while (message_count >= 0) {
    printf("%c", *(msg_ptr + (--message_count)));
  }

  printf("\n");

  return 0;
}
