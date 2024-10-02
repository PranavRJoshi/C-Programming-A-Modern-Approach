// Q. 2a. Write a program that reads a message, then checks whether it's a palindrome (the letters in the message are the same from left to right as from right to left):
//    Enter a message: He lived as a devil, eh?
//    Palindrome
//
//    Enter a message: Madam, I am Adam.
//    Not a palindrome
//
// Ignore all characters that aren't letters. Use integer variables to keep track of positions in the array.
//    2b. Revise the program to use pointers instead of integers to keep track of positions in the array.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MSG_SIZE 50

bool is_palindrome (char *message, int msg_size);

int main (void) {

  char message[MSG_SIZE];
  char *msg_ptr = message;
  char ch;
  bool msg_check;

  for (;;) {
    int msg_count = 0;
    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && msg_count <= MSG_SIZE) {
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        *(msg_ptr + msg_count) = tolower(ch);
        msg_count++;
      }
    }

    msg_check = is_palindrome(msg_ptr, --msg_count);

    if (msg_check) {
      printf("Palindrome.\n");
    } else {
      printf("Not a palindrome.\n");
    }
    printf("\n\n");
  }

  return 0;
}

bool is_palindrome (char *m, int msg) {
  int count = 0;
  while (count <= msg) {
    if (*(m + count) != *(m + msg)) {
      return false;
    }
    count++;
    msg--;
  }
  return true;
}
