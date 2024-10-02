// Q. Modify the qsort.c program of Section 9.6 so that low, high, and middle are pointers to array elements rather than integers. The split function will need to return a pointer, not an integer.

#include <stdio.h>
#include <stdbool.h>

#define LEN 10

void quicksort (int *low, int *high);
int *split (int *low, int *high);

int main (void) {

  int unsorted_arr[LEN] = {0};
  int i;

  printf("Enter %d numbers to be sorted: ", LEN);
  
  for (i = 0; i < LEN; i++) {
    scanf("%d", &unsorted_arr[i]);
  }

  quicksort(&unsorted_arr[0], &unsorted_arr[LEN-1]);

  printf("In sorted order: ");

  for (int j = 0; j < LEN; j++) {
    printf("%d ", *(unsorted_arr + j));
  }

  printf("\n");

  return 0;
}

void quicksort (int *low, int *high) {
  int *middle;

  if (low >= high) {
    return;
  }

  middle = split(low, high);

  quicksort(low, middle - 1);

  quicksort(middle + 1, high);
}

int *split (int *low, int *high) {
  int partition_element = *low;
  bool high_turn = true;

  while (low != high) {
    if (high_turn) {
      if (*high <= partition_element) {
        *low++ = *high;
        high_turn = false;
      } else {
        high--;
      }
    } else {
      if (*low >= partition_element) {
        *high-- = *low;
        high_turn = true;
      } else {
        low++;
      }
    }
  }

  *low = partition_element;

  return low;
}

