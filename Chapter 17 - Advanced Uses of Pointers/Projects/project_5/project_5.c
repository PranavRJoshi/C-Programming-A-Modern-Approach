// Q. Write a program that sorts a series of words enterd by the user:
//    Enter a word: foo
//    Enter a word: bar
//    Enter a word: baz
//    Enter a word: quux
//    Enter a word: 
//    
//    In sorted order: bar baz foo quux
// Assume that each word is no more than 20 characters long. Stop reading when the user enters an empty word (i.e., presses Enter without entering a word). Store each word in a dynamically allocated string, using an array of pointers to keep track of the strings, as in the remind2.c program (Section 17.2). After all words has been read, sort the array (using any sorting technique) and then use a loop to print the words in sorted order. Hint: Use the read_line function to read each word, as in remind2.c.

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

#define WORD_SIZE 20

void sort_string_arr (char **str_arr, int arr_size);

int main (void) {
  char **words;
  char *word;
  int words_count = 0;
  int words_arr_size = 2;

  words = malloc(sizeof(char *) * words_arr_size);
  if (words == NULL) {
    fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory. Exiting.\n");
    exit(EXIT_FAILURE);
  }

  do {
    if (words_count == words_arr_size) {
      printf("[LOG] Expanding the string array storage...\n");
      words_arr_size = 2 * words_arr_size;
      words = realloc(words, sizeof(char *) * words_arr_size);
      if (words == NULL) {
        fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory. Exiting.\n");
        exit(EXIT_FAILURE);
      }
    }
    printf("Enter a word: ");
    word = malloc(WORD_SIZE + 1);
    if (word == NULL) {
      fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory. Exiting.\n");
      exit(EXIT_FAILURE);
    }
    read_line(word, WORD_SIZE);
    *(words + words_count) = word;
    if (word[0] != '\0') {
      words_count++;
    }
  } while (word[0] != '\0');

  // printf("[LOG] %d strings entered.\n", words_count);

  sort_string_arr(words, words_count);

  printf("In sorted order: ");

  for (int i = 0; i < words_count; i++) {
    printf("%s ", *(words + i));
  }

  printf("\n");

  /* freeing up the dynamically allocated string and string array */
  for (int i = 0; i < words_count; i++) {
    free(*(words + i));
    *(words + i) = NULL;
  }
  free(words);
  words = NULL;

  return 0;
}

void sort_string_arr (char **str_arr, int arr_size) {
  char *temp_str;

  for (int i = 0; i < arr_size - 1; i++) {
    for (int j = i + 1; j < arr_size; j++) {
      if (my_strcmp(*(str_arr + i), *(str_arr + j)) > 0) {
        temp_str = *(str_arr + i);
        *(str_arr + i) = *(str_arr + j);
        *(str_arr + j) = temp_str;
        // printf("[LOG] Iteration i,j = %d, %d. Replaced the strings %s and %s\n", i, j, *(str_arr + i), *(str_arr + j));
      }
    }
  }
}
