// Q. Let's develop a recursive function named quicksort that uses the quicksort that uses the Quicksort algorithm to sort an array of integers. To test the function, we'll have main read 10 numbers into an array, call quicksort to sort the array, then print the elements in the array:
//    Enter 10 numbers to be sorted: 9 16 47 82 4 66 12 3 25 51
//    In sorted order: 3 4 9 12 16 25 47 51 66 82
// Since the code for partitioning the array is a bit lengthy, I'll put it in a separate function named split.

#include <stdio.h>
#include <stdbool.h>

#define LEN 10

void quicksort (int unsort_arr[], int low, int high);
int split (int unsort_arr[], int low, int high);

int main (void) {

  int unsorted_arr[LEN] = {0};
  int i;

  printf("Enter %d numbers to be sorted: ", LEN);
  
  for (i = 0; i < LEN; i++) {
    scanf("%d", &unsorted_arr[i]);
  }

  quicksort(unsorted_arr, 0, LEN - 1);

  printf("In sorted order: ");

  for (int j = 0; j < LEN; j++) {
    printf("%d ", unsorted_arr[j]);
  }

  return 0;
}

void quicksort (int unsort_arr[], int low, int high) {
  int middle;

  // termination condition
  if (low >= high) {
    return;
  }

  // middle returns the index at which the low and high meet
  middle = split(unsort_arr, low, high);
  // after the partition, the element in the middle is at the right place
  // we only need to sort the elements that occur before it, hence middle - 1
  quicksort(unsort_arr, low, middle - 1);
  // and the elements that occur after it, hence middle + 1
  quicksort(unsort_arr, middle + 1, high);
}

int split (int unsort_arr[], int low, int high) {
  int partition_element = unsort_arr[low];

  for (;;) {
    // the while loop checks for the following things
    // low < high check if the low pointer is still less than the high pointer, not pointer in literal sense, but you know
    while (low < high && partition_element <= unsort_arr[high]) {
      // if partition_element <= unsort_arr[high], i.e. if the element in the high region is greater than the partition element
      // just decrement the value of h.
      high--;
    }
    // but if low >= high, we have reached the terminating state, so we break out of the loop
    if (low >= high) {
      break;
    }

    // if the above while loop is false and the if condition is not satisfied
    // we need to add the element in the 
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