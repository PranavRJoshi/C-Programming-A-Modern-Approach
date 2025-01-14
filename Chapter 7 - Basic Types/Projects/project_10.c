// Q. Write a program that counts the number of vowels (a, e, i, o, and u) in a sentence:
//    Enter a sentence: And that's the way it is.
//    Your sentence contains 6 vowels.

#include <stdio.h>
#include <ctype.h>

int main (void) {
  
  char ch;
  int vowel_count = 0;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    switch (toupper(ch)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        vowel_count++;
    }
  }

  printf("Your sentence contains %d vowels.\n", vowel_count);

  return 0;
}

