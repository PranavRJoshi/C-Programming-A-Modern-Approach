// Q. (C99) Repeat Exercise 3, but this time use a designated initializer. Make the initializer as short as possible.

#include <stdio.h>
#include <stdbool.h>

int main (void) {

  bool weekend[7] = {[0] = true, [6] = true};

  for (int i = 0; i <  ((int) (sizeof(weekend) / sizeof(weekend[0]))); i++) {
    printf("index %d of array weekend has bool value (1 for true, 0 for false) %d\n", i, weekend[i]); 
  }

  return 0;
}

