// Q. Rewrite the following loop so that its body is empty:
//    for (n = 0; m > 0; n++)
//      m /= 2;

#include <stdio.h>

int main (void) {

  int n, m;

  for (n = 0; m > 0; n++, m /= 2);

  return 0;
}

