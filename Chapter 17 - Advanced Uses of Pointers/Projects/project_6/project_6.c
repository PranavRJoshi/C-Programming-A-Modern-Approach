// Q. Modify Programming Project 5 so that it uses qsort to sort the array of pointers. 

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

#define WORD_SIZE 20

// #define IS_NULL(x)                                                              \
// if ((!x)) {                                                                     \
// fprintf(stderr, "[FATAL ERROR] Failed to allocate sufficient memory.\n");       \
// exit(EXIT_FAILURE);                                                             \
// }

int str_cmp (const void *str_1, const void *str_2);

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
  // IS_NULL(words)

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

  qsort(words, words_count, sizeof(char *), str_cmp);

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

int str_cmp (const void *str_1, const void *str_2) {
  const char **s1 = (const char **) str_1;
  const char **s2 = (const char **) str_2;

  return my_strcmp(*s1, *s2);

  /* Alternate solution, had some cases where it failed. */
  /*  
    Enter a word: hello
    Enter a word: is
    [LOG] Expanding the string array storage...
    Enter a word: this
    Enter a word: not
    [LOG] Expanding the string array storage...
    Enter a word: a
    Enter a word: good
    Enter a word: place
    Enter a word: 
    In sorted order: a hello good is not place this 
  */
  // int str_cmp_res = my_strcmp(*s1, *s2);
  //
  // if (str_cmp_res > 1) {
  //   return 1;
  // } else if (str_cmp_res < 1) {
  //   return -1;
  // } else {
  //   return 0;
  // }
}
