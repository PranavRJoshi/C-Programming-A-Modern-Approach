// Q. Use the techniques of Section 13.6 to condense the count_spaces function of Section 13.4. In particular, replace the for statement by a while loop.

#include <stdio.h>

#define STR_LEN 100

int count_spaces (const char *message);

int main (void) {

  char message[STR_LEN + 1];
  char *msg_ptr = message;

  printf("Enter a message: ");

  while((*msg_ptr++ = getchar()) != '\n') {
    ;
  }

  *--msg_ptr = '\0';

  // printf("[LOG] Message entered: %s", message);

  printf("The message contains %d spaces.\n", count_spaces(message));

  return 0;
}

int count_spaces (const char *m) {
  int count = 0;

  while (*m) {
    // printf("[LOG] character: %c\n", *m);
    if (*m++ == ' ') {
      count++;
    }
  }

  return count;
}
