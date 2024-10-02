// Q. Modify Programming Project 2 from Chapter 12 so that it includes the following function:
//    bool is_palindrome (const char *message);
// The function returns true if the string pointed to by message is a palindrome.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MSG_SIZE 50

bool is_palindrome (char *message);

int main (void) {

  char message[MSG_SIZE + 1];
  char *msg_ptr;
  char ch;
  bool msg_check;

  for (;;) {
    msg_ptr = message;
    int msg_count = 0;
    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && msg_count < MSG_SIZE) {
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        *(msg_ptr + msg_count) = tolower(ch);
        msg_count++;
      }
    }

    *(msg_ptr + msg_count) = '\0';

    // printf("[LOG] The variable message contains: %s\n", message);

    msg_check = is_palindrome(message);

    if (msg_check) {
      printf("Palindrome.\n");
    } else {
      printf("Not a palindrome.\n");
    }
    printf("\n\n");
  }

  return 0;
}

bool is_palindrome (char *m) {
  char *temp_ptr = m;
  
  // previously, i made an array inside the function and made temp_ptr point to that array--DO NOT DO THIS
  // Doing what i did destroys one the important features of pointer. One of the issue is unwanted variable
  // Since the problem here requires to check for palindrome, so we can just make temp_ptr point to the parameter m
  // As temp_ptr is also holding the address (the one that is sent during function call), we can just increment it till we find the null character
  while (*temp_ptr++) {
    ;
  }

  // the reason we need to decrement the pointer by 2 is because after the while loop ends
  // temp_ptr will be pointing past the null character, so decreasing temp_ptr by one will make it point to the null character.
  // decrementing it again will make it point past the last letter in the character array.
  temp_ptr--;
  temp_ptr--;

  // printf("[LOG] The variable temp contains %s\n", temp);

  while (*m) {
    // printf("[LOG] The character in m and temp is: %c and %c\n", *m, *temp_ptr);
    if (tolower(*m++) != tolower(*temp_ptr--)) {
      return false;
    }
  }

  return true;
}

