#include <stdio.h>
#include "stackADT.h"

int main (void) {
  Stack s1, s2;
  int n;

  s1 = create();
  s2 = create();

  push(s1, 1);
  push(s1, 2);

  n = pop(s1);
  printf("Popped %d from s1\n", n);
  push(s2, n);
  n = pop(s1);
  printf("Popped %d from s1\n", n);
  push(s2, n);

  destroy(s1);

  while (!is_empty(s2)) {
    printf("Popped %d from s2\n", pop(s2));
  }

  push(s2, 3);
  make_empty(s2);
  if (is_empty(s2)) {
    printf("s2 is empty\n");
  } else {
    printf("s2 is not empty\n");
  }

  destroy(s2);

  /* Exercise 6(a) */
  Stack s3;
  s3 = create();
  push(s3, 1);
  
  int peek_value;
  peek_value = peek(s3);

  printf("[LOG] The peeked value in s3 is: %d\n", peek_value);
  /* 
   * The value is "peeked", not "popped". 
   * This means the stack s3 should not be empty after the peek call, although it only has one value.
  */
  if(!is_empty(s3)) {
    printf("[LOG] The stack s3 is not empty.\n");
  }

  destroy(s3);

  return 0;
}
