// Q. What output does the following for statement produce?
//    for (i = 10; i >= 1; i /= 2)
//      printf("%d ", i++);
// Expectation: 10 5 3 2 1 1 1 (more 1s to be printed infinitely)
// Actual: 10 5 3 2 1 1 1 1 1 1 1 1 1 1 (infinite 1s)

#include <stdio.h>

int main (void) {

  int i;

  for (i = 10; i >= 1; i /= 2)
      printf("%d ", i++);

  return 0;
}

