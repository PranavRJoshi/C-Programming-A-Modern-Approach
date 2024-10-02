// Q. Simplify Programming Project 2(b) by taking advantage of the fact that an array name can be used as a pointer.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MSG_SIZE 50

bool is_palindrome (const char *message, int msg_size);

int main (void) {

  char message[MSG_SIZE];
  char ch;
  bool msg_check;

  for (;;) {
    int msg_count = 0;
    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && msg_count <= MSG_SIZE) {
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        *(message + msg_count) = tolower(ch);
        msg_count++;
      }
    }

    msg_check = is_palindrome(message, --msg_count);

    if (msg_check) {
      printf("Palindrome.\n");
    } else {
      printf("Not a palindrome.\n");
    }
    printf("\n\n");
  }

  return 0;
}

bool is_palindrome (const char *m, int msg) {
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

