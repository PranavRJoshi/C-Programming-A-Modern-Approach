// Q. Modify the stackADT3.c file of Section 19.4 by adding an int member named len to the stack_type structure. This member will keep track of how many items are currently stored in a stack. Add a new function named length that has a Stack parameter and returns the value of the len member. (Some of the existing functions in stackADT3.c will need to be modified as well.) Modify stackclient.c (project_3.c in my case) so that it calls the length function (and displays the value that it returns) after each operation that modifies a stack.

#include <stdio.h>
#include "stackADT4.h"

int main (void) {

  Stack s;

  s = create();
  printf("[LOG] The length of the stack is: %d\n", length(s));

  push(s, 1);
  printf("[LOG] The length of the stack is: %d\n", length(s));

  push(s, 2);
  printf("[LOG] The length of the stack is: %d\n", length(s));

  Item popped_item = 0;

  popped_item = pop(s);

  printf("[LOG] The popped item is %d and the length is %d\n", popped_item, length(s));

  make_empty(s);
  printf("[LOG] The length of the stack is: %d\n", length(s));

  destroy(s);

  return 0;
}
