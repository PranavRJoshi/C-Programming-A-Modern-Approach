// Q. Modify Programming Project 14 from Chapter 8 so that it stores the words in a two-dimensional char array as it reads the sentence, with each row of the array storing a single word. Assume that the sentence contains no more than 30 words and no word is more than 20 character at the end of each word so that it can be treated as a string.

#include <stdio.h>
#include <ctype.h>

#define WORD_COUNT 30
#define CHARACTER_COUNT 20

int main (void) {

  char sentence[WORD_COUNT][CHARACTER_COUNT];
  char (*msg_ptr)[CHARACTER_COUNT] = sentence;
  char terminating_char;
  int ch;
  int i;
  int j = 0;

  printf("Enter a sentence: ");

  for (i = 0, ch = getchar(); ch != '\n'; ch = getchar()) {
    if (ch == '.' || ch == '?' || ch == '!') {
      terminating_char = ch;
      (*msg_ptr)[i] = '\0'; 
      break;
    }
    if (ch == ' ') {
      (*msg_ptr)[i] = '\0';
      msg_ptr++;
      j++;
      i = 0;
    } else {
      (*msg_ptr)[i] = ch;
      i++;
    }
  }

  for (i = j; i >= 0; i--) {
    printf("%s ", sentence[i]);
  }

  printf("\b%c\n", terminating_char);

  // printf("The terminating character is: %c\n", terminating_char);
  
  return 0;
}

