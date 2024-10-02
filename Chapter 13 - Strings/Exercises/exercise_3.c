#include <stdio.h>

int main (void) {

  int i, j;

  char s[20];

  printf("Enter anything: ");
  scanf("%d%s%d", &i, s, &j);

  printf("Value stored in i: %d\n", i);
  printf("Value stored in s: %s\n", s);
  printf("Value stored in j: %d\n", j);

  printf("\n");

  return 0;
}
