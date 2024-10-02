// Q. What output does the follwing program fragment produce?
//    sum = 0;
//    for (i = 0; i < 10; i++) {
//      if (i % 2)
//        continue;
//      sum += 1;
//    }
//    printf("%d\n", sum);
// Value of sum: 1 2 3 4 (sum is incremented whenever the value of i is an odd number)
// Expectation: 4
// Actual: 5 // Mistake: I forgot 9 is also an odd number

#include <stdio.h>

int main (void) {

  int i, sum = 0;

  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    sum += 1;
  }

  printf("%d\n", sum);

  return 0;
}

