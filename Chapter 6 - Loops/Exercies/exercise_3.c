// Q. What output does the following for statement produce?
// for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
//    printf("%d ", i);
// Expectation: 5 4 3 2 1
// Actual: 5 4 3 2 // Mistake: When the value of i is 2, the value of j will be 1. Next the value of i, i.e. 2 is printed, and the thrid exrepssion of the for loop is executed, i.e. --i => i = 1 and j = i - 1 => j = 0. The comparision is made, the left comparision does not matter as it does not have any side effect, so j > 0 is only used to determine, and since j = 0 is false, the for loop terminates.

#include <stdio.h>

int main (void) {

  int i, j;

  for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);

  return 0;  
}

