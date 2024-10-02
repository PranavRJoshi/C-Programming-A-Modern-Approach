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

  for (;;) {
    while (low < high && partition_element <= unsort_arr[high]) {
      high--;
    }
    if (low >= high) {
      break;
    }

    unsort_arr[low++] = unsort_arr[high];

    while (low < high && partition_element >= unsort_arr[low]) {
      low++;
    }
    if (low >= high) {
      break;
    }

    unsort_arr[high--] = unsort_arr[low];
  }

  unsort_arr[high] = partition_element;

  return high;
}

