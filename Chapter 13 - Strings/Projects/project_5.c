// Q. Write a program named sum.c that adds up its command-line arguments, which are assumed to be integers. Running the program by typing
//    sum 8 24 62
// should produce the following output:
//    Total: 94
// Hint: Use the atoi function to convert each command-line argument from string form to integer form.

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int sum = 0;

  // if the argument is a floating point in the form of string, i.e. "12.24", the atoi("12.24") will convert it to 12.
  for (int i = argc - 1; i > 0; i--) {
    sum += atoi(argv[i]);
  }

  printf("Total: %d\n", sum);
}

