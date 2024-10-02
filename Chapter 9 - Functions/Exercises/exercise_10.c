// Q. Write functions that return the following values. (Assume that a and n are parameters, where a is an array of int values and n is the length of the array.)
//     a) The largest element in a.
//     b) The average of all elements in a.
//     c) The number of positive elements in a.

#include <stdio.h>

// this program does not work for pre C-99 compiler as it utilizes the Variable Length Arrays (VLA)

// a function that takes in variable length array, it is mandatory to have the len parameter precede the array parameter
// see #31 of Chapter's notes
int largest_element (int arr_len, int arr[arr_len]);
// another way to represent a function prototype that has VLA as a parameter, the * represents that
// one of the function parameter gives the length of the array
double average (int arr_len, int arr[*]);
// same as the one for function average, but we need not specifically provide variable name (for function prototype)
int no_of_positive_elements (int, int[*]);

int main (void) {

  int n;
  int highest_element = 0;
  double avg_of_arr = 0.0;
  int positive_element_count = 0;

  printf("Enter the number of elements for an array: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter the elements of the array: ");

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  highest_element = largest_element(n, arr);
  avg_of_arr = average(n, arr);
  positive_element_count = no_of_positive_elements(n, arr);

  printf("For the given array, the following results are obtained.\n");
  printf("The highest element in the array is: %d\n", highest_element);
  printf("The average of all elements is: %lf\n", avg_of_arr);
  printf("The number of positive elements are: %d\n", positive_element_count);

  return 0;
}

int largest_element (int n, int a[n]) {
  int largest = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] > largest) {
      largest = a[i];
    }
  }

  return largest;
}

double average (int n, int a[n]) {
  double avg = 0.0f;
  int total = 0;

  for (int i = 0; i < n; i++) {
    total += a[i];
  }

  avg = (double) total / n;

  return avg;
}

int no_of_positive_elements (int n, int a[n]) {
  int positive_element_count = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      positive_element_count++;
    }
  }

  return positive_element_count;
}

