// Q. Modify Programming Project 5 from Chapter 7 so that it includes the following function:
//    int compute_scrabble value (const char *word);
// The function returns the SCRABBLE value of the string pointed to by word.

#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 100

int compute_scrabble_value (const char *word);

int main (void) {

  char word[WORD_LEN + 1];
  char *word_ptr = word;
  
  printf("Enter a word: ");

  while (!isspace((*word_ptr++ = getchar()))) {
    ;
  }

  *--word_ptr = '\0';

  printf("Scrabble value: %d\n", compute_scrabble_value(word));
  
  return 0;
}

int compute_scrabble_value (const char *w) {

  int scrabble_value = 0;
  
  while (*w != '\0') {
    switch (toupper(*w++)) {
      case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
        scrabble_value += 1;
        break;
      case 'D': case 'G':
        scrabble_value += 2;
        break;
      case 'B': case 'C': case 'M': case 'P': 
        scrabble_value += 3;
        break;
      case 'F': case 'H': case 'V': case 'W': case 'Y':
        scrabble_value += 4;
        break;
      case 'K':
        scrabble_value += 5;
        break;
      case 'J': case 'X':
        scrabble_value += 8;
        break;
      case 'Q': case 'Z':
        scrabble_value += 10;
        break;
    } 
  }

  return scrabble_value;
}

