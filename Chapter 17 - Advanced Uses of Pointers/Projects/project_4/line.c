#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h" 

#define MAX_LINE_LEN 60

struct v_line_ll {
  struct v_line_ll *prev;
  struct v_line_ll *next;
  char word[];    /* C99 only, if C89, then initialize with word[1] */
} *line = NULL;

int line_len  = 0;
int num_words = 0;

void clear_line (void) {
  if (line != NULL) {
    struct v_line_ll *temp;
    while (line != NULL) {
      temp = line;
      line = line->next;
      free(temp);
    }
  }
  // line = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word (const char *word) {
  
  struct v_line_ll *temp;
  int word_len = strlen(word) + 1;    /* one up to account for the null character */

  temp = malloc(sizeof(struct v_line_ll) + word_len);

  if (temp == NULL) {
    fprintf(stderr, "[ERROR] Failed to allocate sufficient memory. Exiting.\n");
    exit(EXIT_FAILURE);
  }

  strlcpy(temp->word, word, word_len);

  if (line != NULL) {
    line->prev  = temp;
  }

  temp->next  = line;
  temp->prev  = NULL;
  line        = temp;

  line_len = line_len + strlen(word) + 1;   /* One up to account for the space character that is assumed to be after every word. */
  num_words++;
}

int space_remaining (void) {
  return MAX_LINE_LEN - line_len;
}

void write_line (void) {
  int extra_spaces, spaces_to_insert, j;

  // printf("[DEBUG] The line len is: %d\n", line_len);

  struct v_line_ll *temp;
  
  /* scenario when the line struct does not point to any valid node. */
  if (line == NULL) {
    fprintf(stderr, "[FATAL ERROR] No words to add in the line.\n");
    return;
  }

  /* Traverse the doubly linked list until the first node is reached.
   * The struct contains struct pointer variable next and prev for this reason.
   * The prev will point to the previous node, the next will point to the next one.
  */
  while (line->next != NULL) {
    line = line->next;
  }

  extra_spaces = MAX_LINE_LEN - line_len;
  for (; line != NULL;) {
    printf("%s", line->word);

    // printf("************************DEBUG********************\n"                                  \
    //        "Curr_addr           Content           Prev_addr       Next_addr\n"                    \
    //        "---------           -------           ---------       ---------\n"                    \
    //        "%15p    %10s    %15p    %15p\n"                                                       \
    //        "************************END**********************\n", (void *) line, line->word, (void *) line->prev, (void *) line->next);

    /* Here's the flow of printing the words:
     *    1. line variable contains the word member that is printed in each iteration
     *    2. temp is the variable that is used to get the node that needs to be freed.
     *    3. After the word has already been printed, line should point to the "previous node".
     *    4. temp is later freed, to make sure no memory leak is present.
    */
    temp = line;
    line = line->prev;
    free(temp);

    /* Related to add sufficient number of spaces to justify the content.
     * extra_spaces can be zero, in an ideal case, but can be like 5, or
     * any arbitrary number. This is because before a word is added, it is 
     * checked if the word after adding makes the size of line_len greater 
     * than MAX_LINE_LEN. If this is the case, the write_line function is 
     * invoked.
    */
    spaces_to_insert = extra_spaces / (num_words - 1);
    for (j = 1; j <= spaces_to_insert + 1; j++) {
      putchar(' ');
    }
    extra_spaces -= spaces_to_insert;
    num_words--;
  }
  putchar('\n');
}

void flush_line (void) {
  if (line_len > 0) {
    struct v_line_ll *temp = line;

    while (line->next != NULL) {
      line = line->next;
    }

    while (line != NULL) {
      temp = line;
      printf("%s ", temp->word);
      line = line->prev;
      free(temp);
    }
  }
  printf("\n");
}

