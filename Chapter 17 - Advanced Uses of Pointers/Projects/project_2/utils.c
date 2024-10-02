#include "utils.h"
#include <stdio.h>
#include <ctype.h>

int read_line (char *str, int n) {
  int len = 0;
  int ch;

  while (isspace(ch = getchar())) {
    ;
  }

  while (ch != '\n') {
    if (len < n) {
      *(str + len) = ch;
      len++;
    }
    ch = getchar();
  }

  *(str + len) = '\0';
  return len;
}

void clear_input_stream() {
  int ch;

  while ((ch = getchar()) != '\n') {
    ;
  }
}

