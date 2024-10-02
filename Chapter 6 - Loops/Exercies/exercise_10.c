// Q. Show how to replace a continue statement by an equivalent goto statemnt.

#include <stdio.h>

int main (void) {

  int i;

  // using the continue statement
  for (i = 10; i >= 0; i--) {
    if (i == 1)
      continue;
    printf("%d ", i);
  }

  printf("\n");

  int j;

  // using the goto statement
  for (j = 10; j >= 0; j--) {
    if (j == 1)
      goto jmp_one;
    printf("%d ", j);
  jmp_one: ;
  }
  
  return 0;
}

