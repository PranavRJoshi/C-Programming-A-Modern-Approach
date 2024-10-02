// Most of the functions in line.c are easy to write. The only tricky one is write_line, which writes a line with justification. write_line writes the characters in line one by one, passing at the space between each pair of words to write additional spaces if needed.
// The number of additional spaces is stored in spaces_to_insert, which has the values extra_spaces / (num_words - 1), where extra_spaces is initially the difference between the maximum line length and the actual line length. Since extra_spaces and num_words change after each word is printed, spaces_to_insert will change as well.
// If extra_spaces is 10 initially and num_words is 5, then the first word will be followed by 2 extra space, the second by 2, the third by 3, and the fourth by 3.

#include <stdio.h>
#include <string.h>
#include "line.h" 

#define MAX_LINE_LEN 60 

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

// clears the line by making the first index of line array a null character, making the line_len 0, and number of words as 0.
void clear_line (void) {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

// When the first word is being added, only the concatenation of the line (which is of length 0 initially) with the word (21 characters max) is done 
void add_word (const char *word) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining (void) {
  return MAX_LINE_LEN - line_len;
}

void write_line (void) {
  int extra_spaces, spaces_to_insert, i, j;

  // NOTE: Not all lines will have words (including spaces) that have exactly 60 characters. So, say that the current line_len is 50 and the next words is of length 15, then there needs to be 10 extra spaces in the current line. 
  extra_spaces = MAX_LINE_LEN - line_len;
  // printf("[LOG] The value of extra spaces is: %d\n", extra_spaces);
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ') {
      putchar(line[i]);
    } else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++) {
        putchar(' ');
      }
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line (void) {
  if (line_len > 0) {
    puts(line);
  }
}
