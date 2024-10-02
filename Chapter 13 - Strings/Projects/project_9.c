// Q. Modify Programming Project 10 from Chapter 7 so that it includes the following function:
//    int compute_vowel_count (const char *sentence);
// The function returns the number of vowels in the string pointed to by the sentence parameter.

#include <stdio.h>
#include <ctype.h>

#define STR_LEN 100

int compute_vowel_count (const char *sentence);

int main (void) {
  
  char message[STR_LEN + 1];
  char *msg_ptr = message;

  printf("Enter a sentence: ");

  while ((*msg_ptr++ = getchar()) != '\n') {
    ;
  }

  *--msg_ptr = '\0';

  printf("Your sentence contains %d vowels.\n", compute_vowel_count(message));

  return 0;
}

int compute_vowel_count (const char *s) {
  int vowel_count = 0;

  while (*s != '\0') {
    switch (toupper(*s++)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        vowel_count++;
    }
  }

  return vowel_count;
}
