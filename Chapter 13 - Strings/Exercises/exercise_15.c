#include <stdio.h>

int f (char *s, char *t);

int main (void) {
  char str_1[20];
  char str_2[20];

  int result;

  printf("Enter two words: ");
  scanf("%s%s", str_1, str_2);

  result = f(str_1, str_2);

  printf("The result obtained is: %d\n", result);

  return 0;
}

int f (char *s, char *t) {
  char *p1, *p2;

  for (p1 = s; *p1; p1++) {
    for (p2 = t; *p2; p2++) {
      if (*p1 == *p2) {
        break;
      }
    }
    if (*p2 == '\0') {
      break;
    }
  }
  return p1 - s;
}

