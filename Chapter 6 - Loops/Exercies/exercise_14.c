// Q. Find the error in the following program fragment and fix it.
//    if (n % 2 == 0);
//      printf("n is even\n");
// Error: The given if statement is a null statement. Since the if statement has the semicolon at the end, even if the condition is false, i.e. n % 2 gives a result of 1, the below printf statement is executed. To fix this, we can simply remove the semicolon at the end of if statement.

#include <stdio.h>

int main (void) {

  int n = 10;

  if (n % 2 == 0)
    printf("n is even\n");

  return 0;
}

