// Q. Write the following function:
//    void swap (int *p, int *q);
// When passed the addresses of two variables, swap should exchange the values of the variables:
//    swap (&i, &j);    /* exchanges values of i and j */

#include <stdio.h>

void swap (int *p, int *q);

int main (void) {

  int i, j;

  printf("Enter two numbers: ");
  scanf("%d%d", &i, &j);

  swap(&i, &j);

  printf("The swapped numbers are: %d and %d\n", i, j);

  return 0;
}

void swap (int *p, int *q) {
  *p = *p + *q;
  *q = *p - *q;
  *p = *p - *q;
}
