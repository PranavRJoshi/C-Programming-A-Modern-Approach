// Q. Write a program that tests whether two words are anagrams (permutations of the same letters):
//    Enter first word: smartest
//    Enter second word: mattress
//    The words are anagrams.
//
//    Enter first word: dumbest
//    Enter second word: stumble
//    The words are not anagrams.
// Write a loop that reads the first word, character by character, using an array of 26 integers to keep track of how many times each letter has been seen. (For example, after the word smartest has been read, the array should contain the values 1 0 0 0 1 0 0 0 0 0 0 0 1 2 2 0 0 0 0 0 0, reflecting the fact that smartest contains one a, one e, one m, one r, two s's and two t's.) Use another loop to read the second word, except this time decrementing the corresponding array element as each letter is read. Both loops should ignore any characters that aren't letters, and both should treat upper-case letters in the same way as lower-case letters. After the second word has been read, use a third loop to check whether all the elements in the array are zero. If so, the words are anagrams. Hint: You may wish to use functions from <ctype.h>, such as isalpha and tolower.

// int isalpha (int) -> retruns true if the argument provided is true for tolower() and toupper(), i.e. if the argument is an alphabetic character
// 

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main (void) {

  char ch;

  int letter_count_track[26] = {0};

  bool is_anagram = true;

  printf("Enter first word: ");

  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      letter_count_track[tolower(ch) - 'a'] += 1;
    }
  }

  printf("Enter second word: ");

  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      letter_count_track[tolower(ch) - 'a'] -= 1;
    }
  }
  
  for (int i = 0; i < 26; i++) {
    if (letter_count_track[i] != 0) {
      is_anagram = false;
    }
  }
  
  if (is_anagram) {
    printf("The words are anagrams.");
  } else {
    printf("The words are not anagrams.");
  }

  return 0;
}

