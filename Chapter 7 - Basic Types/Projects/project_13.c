// Q. Write a program that calculates the average word length for a sentence:
//    Enter a sentence: It was deja vu all over again.
//    Average word length: 3.4
// For simplicity, your program should consider a punctuation mark to be part of the word to which it is attached. Display the average word ength to one decimal place.

#include <stdio.h>

int main (void) {

  int word_count = 0;
  int character_count = 0;
  float avg_word_length = 0.0f;
  char ch;

  printf("Enter a sentence: ");
  
  while ((ch = getchar()) != '\n') {
    if (ch == ' ') {
      word_count++;
      continue;
    }
    character_count++;
  }
  
  // this is done becuase the last word won't be counded as the loop terminates before it enters the if statement.
  word_count++;

  avg_word_length = (float) character_count / word_count;

  printf("Average word length: %.1f\n", avg_word_length);

  return 0;
}

