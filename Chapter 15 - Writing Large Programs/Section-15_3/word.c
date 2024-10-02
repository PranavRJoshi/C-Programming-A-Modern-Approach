// Now it's time to write word.c. Although the word.h header file has a prototype for only one function, read_word, we can put additional functions in word.c if we need to. As it turns out, read_word is easier to write if we add a small "helper" function, read_char. We'll assign the task of reading a character and, if it's a new-line character or tab, converting it to a space. Having read_word call read_char instead of getchar solves the problem of treating new-line characters and tabs as spaces.
//
// Before we discuss read_word, a couple of comments are in order concerning the use of getchar in the read_char function. First, getchar returns an int value instead of a char value; that's why the variable ch in read_char is declared to have type int and why the return type of read_char is int. Also, getchar returns the value EOF when it's unable to continue reading (usually becuase it has reached the end of the input file).
//
// read_word consists of two loops. The first loop skips over spaces, stopping at the first nonblank character. (EOF isn't blank, so the loop stops if it reaches the end of the input file.) The second loop reads characters until encountering a space or EOF. The body of the loop stores the characters in word until reaching the len limit. After that, the loop continues reading characters but doesn't store them. The final statement in read_word ends the word with a null character, thereby making it a string. If read_word encounters EOF before finding a nonblank character, pos will be 0 at the end, making word an empty string. 


#include <stdio.h>
#include "word.h" 

int read_char (void) {
  int ch = getchar();

  if (ch == '\n' || ch == '\t') {
    return ' ';
  }
  return ch; 
}

void read_word (char *word, int len) {
  int ch, pos = 0;

  while ((ch = read_char()) == ' ') {
    ;
  }
  while (ch != ' ' && ch != EOF) {
    if (pos < len) {
      word[pos++] = ch;
    }
    ch = read_char();
  }
  word[pos] = '\0';
}

