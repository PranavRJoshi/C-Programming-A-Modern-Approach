// Q. Modify the qsort.c program of Section 9.6 so that the quicksort and split functions are in a separate file named quicksort.c. Create a header file named quicksort.h that contains prototypes for the two functions and have both qsort.c and quicksort.c include this file. 

#include <stdio.h>
#include "quicksort.h"

#define LEN 10

int main (void) {

  int unsorted_arr[LEN] = {0};
  int i;

  printf("Enter %d numbers to be sorted: ", LEN);
  
  for (i = 0; i < LEN; i++) {
    scanf("%d", &unsorted_arr[i]);
  }

  quicksort(unsorted_arr, 0, LEN - 1);

  printf("In sorted order: ");

  for (i = 0; i < LEN; i++) {
    printf("%d ", unsorted_arr[i]);
  }

  return 0;
}

