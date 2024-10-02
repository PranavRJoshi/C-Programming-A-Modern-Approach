#include <stdbool.h>
#include "quicksort.h"

void quicksort (int unsort_arr[], int low, int high) {
  int middle;

  if (low >= high) {
    return;
  }

  middle = split(unsort_arr, low, high);

  quicksort(unsort_arr, low, middle - 1);

  quicksort(unsort_arr, middle + 1, high);
}

int split (int unsort_arr[], int low, int high) {
  int partition_element = unsort_arr[low];
  bool high_turn = true;

  while (low != high) {
    if (high_turn) {
      if (unsort_arr[high] <= partition_element) {
        unsort_arr[low++] = unsort_arr[high];
        high_turn = false;
      } else {
        high--;
      }
    } else {
      if (unsort_arr[low] >= partition_element) {
        unsort_arr[high--] = unsort_arr[low];
        high_turn = true;
      } else {
        low++;
      }
    }
  }

  unsort_arr[low] = partition_element;

  return low;
}

