#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int read_line (char str[], int len) {
  int ch, i = 0;

  while (isspace(ch = getchar())) {
    ;
  }

  while (ch != '\n' && ch != EOF) {
    if (i < len) {
      str[i++] = ch;
    }
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}

// The expression
//    isspace(ch = getchar())
// controls the first while statement. This expression calls getchar to read a character, stores the character into ch, and then uses the usspace function to test whether ch is a white-space character. If not, the loop terminates with ch containing a character that's not white space. Section 15.3 explains why ch has type int instead of char and why it's good to test for EOF.

