// Q. Using the shortcuts described in Section 8.2, shrink the initializer for the segments array (Exercise 6) as much as you can.

#include <stdio.h>

int main (void) {

  const int segments[10][7] = {{1, 1, 1, 1, 1, 1},
                               {[1] = 1, [2] = 1},
                               {1, 1, 0, 1, 1, 0, 1},
                               {1, 1, 1, 1, [6] = 1},
                               {0, 1, 1, [5] = 1, 1},
                               {1, 0, 1, 1, 0, 1, 1},
                               {1, 0, 1, 1, 1, 1, 1},
                               {1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 0, 1, 1}};
  // athough the program runs as intented, it is a good idea to use designator with great care
  // if there were no inner braces, the designator would be of the form segments[m][n] = {[i][j] = 1, ...}
  // but, to be on the safe side, try to adjust the two-dimensional array such that as described in #22 of notes for this chapter.

  for (int i = 0; i < ((int) (sizeof(segments) / sizeof(segments[0]))); i++) {
    printf("Seven segment for digit %d has the following segments on: ", i);
    for (int j = 0; j < ((int) (sizeof(segments[0]) / sizeof(segments[0][0]))); j++) {
      printf("%d ", segments[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}


