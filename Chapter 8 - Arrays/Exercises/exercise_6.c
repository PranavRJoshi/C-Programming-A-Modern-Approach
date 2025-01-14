// Q. Calculators, watches, and other electronic devices often rely on seven-segment displays for numerical output. To form a digit, such devices "turn on" some of the seven segments while leaving others off:
/*
 *
 *
 *     _       _    _         _    _   _    _    _
 *    | |  |   _|   _|  |_|  |_   |_    |  |_|  |_|
 *    |_|  |  |_    _|    |   _|  |_|   |  |_|   _|
 *
 *
 * */
// Suppose that we want to set up an array that remembers which segments should be "on" for each digit. Let's number the segments as follows:
/*
 *
 *
 *      --0--
 *     |     |
 *     5     1
 *     |     |
 *      --6--
 *     |     |
 *     4     2
 *     |     |
 *      --3--
 *
 *
 * */
// Here's what the array might look like, with each row representing one digit:
//    const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, ...}
// I've given you the first row of the initializer; fill in the rest.

#include <stdio.h>

int main (void) {

  const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                               {0, 1, 1, 0, 0, 0, 0},
                               {1, 1, 0, 1, 1, 0, 1},
                               {1, 1, 1, 1, 0, 0, 1},
                               {0, 1, 1, 0, 0, 1, 1},
                               {1, 0, 1, 1, 0, 1, 1},
                               {1, 0, 1, 1, 1, 1, 1},
                               {1, 1, 1, 0, 0, 0, 0},
                               {1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 0, 1, 1}};

  for (int i = 0; i < ((int) (sizeof(segments) / sizeof(segments[0]))); i++) {
    printf("Seven segment for digit %d has the following segments on: ", i);
    for (int j = 0; j < ((int) (sizeof(segments[0]) / sizeof(segments[0][0]))); j++) {
      printf("%d ", segments[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

