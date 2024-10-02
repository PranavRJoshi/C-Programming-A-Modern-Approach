#include "utils.h"
#include <stdio.h>
#include <ctype.h>

int read_line (char *str, int n) {
  int count = 0, ch;

  while ((ch = getchar()) != '\n') {
    if (count < n) {
      *(str + count) = ch;
      count++;
    }
  }
  
  *(str + count) = '\0';
  return count;
}

int my_strcmp (const char *s1, const char *s2) {
  for (; *s1 == *s2; s1++, s2++) {
    if (*s1 == '\0') {
      return 0;
    }
  }
  return *s1 - *s2;
}

