// Q. Modify stackADT2.c so that a stack automatically doubles in size when it becomes full. Have the push function dynamically allocate a new array that's twice as large as the old one and then copy the stack contents from the old array to the new one. Be sure to have push deallocate the old array once the data has been copied.

#include <stdio.h>
#include "stackADT3.h"

int main (void) {

  Stack s1;

  s1 = create(2);

  push(s1, 10);
  push(s1, 20);

  push(s1, 30);
  push(s1, 40);
  push(s1, 50);
  push(s1, 60);

  push(s1, 70);

  int popped_item = 0;
  
  for (int i = 0; i < 7; i++) {
    popped_item = pop(s1);
    printf("[LOG] The popped item is: %d\n", popped_item);
  }

  return 0;
}
