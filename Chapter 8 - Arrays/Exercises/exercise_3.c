// Q. Write a declaration of an array named weekend containing seven bool values. Include an initializer that makes the first and last values true; all other values should be false.

#include <stdio.h>
#include <stdbool.h>

int main (void) {

  bool weekend[7] = {true, false, false, false, false, false, true};

  for (int i = 0; i <  ((int) (sizeof(weekend) / sizeof(weekend[0]))); i++) {
    printf("index %d of array weekend has bool value (1 for true, 0 for false) %d\n", i, weekend[i]); 
  }

  return 0;
}
