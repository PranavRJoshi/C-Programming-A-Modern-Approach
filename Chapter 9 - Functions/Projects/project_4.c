// Q. Modify Programming Project 16 from Chapter 8 so that it includes the following functions:
//    void read_word (int counts[26]);
//    bool equal_array (int counts1[26], int counts2[26]);
// main will call read_word twice, once for each of the two words entered by the user. As it reads a word, read_word will use the letters in the word to update the counts array, as described in the original project. (main will declare two arrays, one for each word. These arrays are used to track how many times each letter occurs in the words.) main will then call equal_array, passing it the two arrays. equal_array will return true if the elements in the two arrays are identical (indicating that the words are anagrams) and false otherwise.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// providing the array subscipt isn't really necessary but it does help document the code
// see #67 of Chapter's note
void read_word (int counts[26]);
bool equal_array (int counts1[26], int counts2[26], int arr_len);

int main (void) {

  int word_count_1[26] = {0};
  int word_count_2[26] = {0};
  bool is_anagram;

  read_word(word_count_1);
  read_word(word_count_2);

  // no need to have a variable for the parameter arr_len as there is exactly 26 characters in the english alphabet
  is_anagram = equal_array(word_count_1, word_count_2, 26);

  if (is_anagram) {
    printf("The given words are anagrams.\n");
  } else {
    printf("The given words are not anagrams.\n");
  }

  return 0;
}

void read_word (int c[26]) {

  char ch;

  printf("Enter a word: ");

  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      c[tolower(ch) - 'a'] += 1;
    }
  }
}

bool equal_array (int c1[26], int c2[26], int n) {
  for (int i = 0; i < n; i++) {
    if (c1[i] != c2[i]) {
      return false;
    }
  }
  return true;
}

