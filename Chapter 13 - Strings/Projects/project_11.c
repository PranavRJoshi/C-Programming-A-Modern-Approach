// Q. Modify Programming Project 13 from Chapter 7 so that it includes the following function:
//    double compute_average_word_length (const char *sentence);
// The function returns the average length of words in the string pointed by sentence.

#include <stdio.h>
#include <ctype.h>

#define MSG_LEN 100

double compute_average_word_length (const char *sentence);

int main (void) {

  char sentence[MSG_LEN + 1];
  char *msg_ptr = sentence;

  printf("Enter a sentence: ");

  while ((*msg_ptr++ = getchar()) != '\n') {
    ;
  }

  *--msg_ptr = '\0';

  printf("The average word length is: %.2lf\n", compute_average_word_length(sentence));
  
  return 0;
}

double compute_average_word_length (const char *s) {
  int word_count = 0;
  int character_count = 0;
  double average = 0.0;

  while (*s) {
    if (*s == ' ') {
      word_count++;
    }
    // not taking any punctuations into account.
    if (isalpha(*s)) {
      character_count++;
    }
    s++;
  }

  word_count++;

  average = (double) character_count / word_count;

  return average;
}
