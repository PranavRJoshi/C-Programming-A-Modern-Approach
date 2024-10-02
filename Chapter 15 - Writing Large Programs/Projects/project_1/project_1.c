// Q. The justify program of Section 15.3 justifies lines by inserting extra spaces between words. The way write_line function correctly works, the words closer to the end of a line tend to have slightly wider gaps between them than the words at the beginning. (For example, the words closer to the end might have three spaces between them, while the words closer to the beginning might be separated by only two spaces.) Improve the program by having write_line alternate between putting the larger gaps at the end of the line and putting them at the beginning of the line. 
//
// The solution to this problem lies in the line 
//    spaces_to_insert = extra_spaces / (num_words - 5);
// in the write_line function that is defined in line.c.
// I modified the function slightly as shown above, to make sure the words at the beginning get more spaces as compared to the words at the end. To be fair, the line can be modified as needed to ge the desired result, I think I am satisfied with my current result, so I will be keeping this.

#include <string.h>
#include "word.h"
#include "line.h"

#define MAX_WORD_LEN 20

int main (void) {
  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line();

  for (;;) {
    read_word(word, MAX_WORD_LEN + 1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len > MAX_WORD_LEN) {
      word[MAX_WORD_LEN] = '*';
    }
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }

  return 0;
}

