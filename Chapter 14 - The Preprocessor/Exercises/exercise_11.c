// Q. (C99) C Programmers often use the fprintf function to write error messages:
//    fprintf(stderr, "Range error: index = %d\n", index);
// stderr is C's "standard error" stream; the remaining arguments are the same as as those for printf, starting with the format string. Write a macro named ERROR that generates the call of fprintf shown above when given a format string and the items to be displayed:
//    ERROR("Range error: index = %d\n", index);

#include <stdio.h>

#define ARR_LEN 10

#define ERROR(msg, value)           \
fprintf(stderr, #msg, value)

int main (void) {

  int arr[ARR_LEN] = {0};
  int index, value;

  printf("Enter the index (0-%d) and the value that needs to be added to that index: ", ARR_LEN - 1);
  while (scanf("%d%d", &index, &value) != 2) {
    ;
  }

  if (index > (ARR_LEN - 1)) {
    ERROR(Range Error: index = %d\n, index);
  } else {
    arr[index] = value;
    for (int i = 0; i < ARR_LEN; i++) {
      printf("Element %d has the value: %d\n", i, arr[i]);
    }
  }

  return 0;
}
