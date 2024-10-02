#include <stdio.h>
#include <string.h>

#define STR_LEN 100

int main(void) {

  char s1[STR_LEN + 1];
  char s2[STR_LEN + 1];

  strcpy(s1, "computer");
  strcpy(s2, "science");
  if (strcmp(s1, s2) < 0)
    strcat(s1, s2);
  else
    strcat(s2, s1);
  s1[strlen(s1) - 6] = '\0';

  printf("s1 now contains: %s", s1);

  // Using this to print the new-line charaacter purpose only
  puts("");

  printf("s2 now contains: %s", s2);

  puts("");

  return 0;
}
