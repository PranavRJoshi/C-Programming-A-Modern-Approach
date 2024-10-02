// Q. Write a program that asks the user to enter a series of integers (which it stores in an array), then sorts the integers by calling the function selection_sort. When given an array with n elements, selection sort must do the following:
//    1. Search the array to find the largest element, then move it to the last position in the array.
//    2. Calls itself recursively to sort the first n - 1 elements of the array.

#include <stdio.h>

void selection_sort (int arr_len, int unsort_arr[arr_len]);

int main (void) {

  int n;

  printf("Enter the number of elements that needs to be sorted: ");
  scanf("%d", &n);

  int unsort_arr[n];

  printf("Enter the elements: ");

  for (int i = 0; i < n; i++) {
    scanf("%d", &unsort_arr[i]);
  }

  // we can simply call the function as the array is not passed as value, see #27 of Chapter's note.
  selection_sort(n, unsort_arr);

  printf("The sorted array is: ");

  for (int i = 0; i < n; i++) {
    printf("%d ", unsort_arr[i]);
  }

  printf("\n");

  return 0;
}

void selection_sort (int n, int a[n]) {

  // when the array reaches the size of 1 (or 0, but that shouldn't happen) then just return
  // as we know it must hold the smallest element.
  if (n <= 1) {
    return;
  }

  // put the first element as the reference "largest" element
  int largest_element = a[0];
  // use the swapped index to swap the value of largest element and the element at the last index 
  int swapped_index = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] > largest_element) {
      largest_element = a[i];
      swapped_index = i;
    }
  }

  // say that the largest number was found at array subscript 2 and the array has the length of 5
  // then we need to first swap the element at the final array subscript to the position where the largest element was found, i.e. 2
  a[swapped_index] = a[n-1]; 
  // then only store the largest element at the final array subscript, for the array of length 5, the array subscript will be 4.
  a[n-1] = largest_element;

  // call the function again, but now, decrement the array subscript by 1 as the final subscript already holds the largest element 
  selection_sort(n-1, a);
}

