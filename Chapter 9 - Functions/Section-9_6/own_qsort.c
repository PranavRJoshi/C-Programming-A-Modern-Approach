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
  // when the value of low is greater than or equal to high
  // we know that there is no more partition that needs to be done
  if (low >= high) {
    return;
  }

  // used to retrieve the index at which the partitioned element is stored at
  middle = split(unsort_arr, low, high);

  // start the quicksort again, but from the low index to the one just before the middle index
  quicksort(unsort_arr, low, middle - 1);

  // start the quicksort again, but from the element just after the middle index to the high index
  quicksort(unsort_arr, middle + 1, high);
}

int split (int unsort_arr[], int low, int high) {
  // use the first element as the partition element
  int partition_element = unsort_arr[low];
  // using this variable as a flag that helps illustrate the sorting used in the book
  bool high_turn = true;

  // at one point, the low "pointer" and the high "pointer" will meet up at a common index
  while (low != high) {
    // when high_turn is set, the high "pointer" checks for element that are smaller than the partition element
    if (high_turn) {
      // if there is such element, it places that respective element into the low "pointer" position
      // and resets the high_turn flag, indicating the turn for the low "pointer" to start searching up
      if (unsort_arr[high] <= partition_element) {
        unsort_arr[low++] = unsort_arr[high];
        high_turn = false;
      } else {
        // if the current high "pointer" does not hold a smaller element, the high "pointer" is moved to the element on the right (next element)
        // the flag is not reset, so it's still the turn for the high "pointer" to traverse
        high--;
      }
    } else {
      // when high_turn is reset, the low "pointer" traverses through the array
      // and checks if the element on the left "pointer" region is larger than the partition_element
      // if so, it places the element into the high "pointer" region and decrement the value of high
      // and again sets the high_turn, indicating the turn for the high "pointer" to start searching up
      if (unsort_arr[low] >= partition_element) {
        unsort_arr[high--] = unsort_arr[low];
        high_turn = true;
      } else {
        // if the current left "pointer" does not hold a larger element, the value of low is imcremented
        // the flag is not reset, so it's still the turn for the low "pointer" to traverse
        low++;
      }
    }
  }

  // high and low are essentially a placeholder index for the partition_element, so we need to add the value to it's respective index.
  unsort_arr[low] = partition_element;
  // or
  // unsort_arr[high] = partition_element;

  // returns the index at which the partition has been done
  return low;
  // or
  // return high
}
