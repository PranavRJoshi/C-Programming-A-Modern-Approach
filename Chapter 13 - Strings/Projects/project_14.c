// Q. Modify Programming Project 16 from Chapter 8 so that it includes the following function:
//    bool are_anagrams (const char *word1, const char *word2);
// The function returns true if the strings pointed to by word1 and word2 are anagrams.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define WORD_LEN 100

bool are_anagrams (const char *word1, const char *word2);

int main (void) {

  char ch;
  char first_word[WORD_LEN + 1];
  char second_word[WORD_LEN + 1];
  char *word_ptr;
  bool is_anagram;

  printf("Enter first word: ");
  word_ptr = first_word;
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      *word_ptr++ = ch;
    }
  }

  *word_ptr = '\0';

  printf("Enter second word: ");
  word_ptr = second_word;
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      *word_ptr++ = ch;
    }
  }

  *word_ptr = '\0';

  is_anagram = are_anagrams(first_word, second_word);

  if (is_anagram) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return 0;
}

bool are_anagrams (const char *fw, const char *sw) {
  int letter_count[26] = {0};
  int *lc_ptr = letter_count;

  while (*fw) {
    (*(lc_ptr + tolower(*fw++) - 'a'))++;
  }

  while (*sw) {
    (*(lc_ptr + tolower(*sw++) - 'a'))--;
  }

  for (int i = 0; i < 26; i++) {
    if (*(lc_ptr + i) != 0) {
      return false;
    }
  }

  return true;
}

