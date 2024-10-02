// Q. Modify the stackADT.h and stackADT3.c files of Section 19.4 so that a stack stores values of type void *, as described in Section 19.5; the Item type will no longer be used. Modify stackclient.c so that it stores pointers to strings in the s1 and s2 stacks.
//
// A little note: It is possible to give the argument a pointer to other data type such as a pointer to integer, which is not handled by the program.

#include <stdio.h>
#include "stackADT4.h"
#include "stackADT.h"

int main (void) {

  Stack_ll sll;

  sll = create_ll();

  push_ll(sll, "Hello, World!");

  char *text_ll;

  text_ll = pop_ll(sll);

  printf("[ADT3 LOG] The popped string is: %s\n", text_ll);
  
  Stack s;

  s = create();

  push(s, "!dlroW ,olleH");
  
  char *text;

  text = pop(s);

  printf("[ADT1 LOG] The popped string is: %s\n", text);


  return 0;
}
