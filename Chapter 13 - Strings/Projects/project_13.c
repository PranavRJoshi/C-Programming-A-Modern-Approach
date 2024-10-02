// Q. Modify Programming Project 15 from Chapter 8 so that it includes the following function:
//    void encrpyt (char *message, int shift);
// The function expects message to point to a string containing the message to be encrypted; shift represents the amount by which each letter in the message is to be shifted.

#include <stdio.h>
#include <ctype.h>

#define MSG_LENGTH 80

void encrypt (char *message, int shift);

int main (void) {

  char message[MSG_LENGTH + 1];
  char *msg_ptr = message;
  int shift_amount;

  printf("Enter message to be encrypted: ");

  while ((*msg_ptr++ = getchar()) != '\n') {
    ;
  }

  *--msg_ptr = '\0';

  printf("Enter shift amount (1-25): ");
  while (scanf("%d", &shift_amount) != 1) {
    ;
  }

  encrypt(message, shift_amount);

  printf("Encrypted message: %s", message);

  printf("\n");

  return 0;
}

void encrypt (char *m, int s) {
  while (*m != '\0') {
    if (*m >= 'a' && *m <= 'z') {
      *m = ((*m - 'a') + s) % 26 + 'a';
    } else if (*m >= 'A' && *m <= 'Z') {
      *m = ((*m - 'A') + s) % 26 + 'A';
    }
    m++;
  }
}

