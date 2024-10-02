// Q. Let a be an array of 100 integers. Write a call of qsort that sorts only the last 50 elements in a. (You don't need to write the comparison function).
//
// qsort requires a non-null function in the fourth argument, i.e. in the comparison function. The answer prvoided states:
//    [was #14] Assuming that compare is the name of the comparison function, the following call of qsort will sort the last 50 elements of a: 
//    qsort(&a[50], 50, sizeof(a[0]), compare);
//
// So, we NEED to have the comparison function, the question seem to suggest to use the comparison function we made during the chapter.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 100

/*
 * compare: compares the elements, returns 1 if element_1 is greater than element_2. -1 if 
 *          element_1 is less than element_2, and 0 if element_1 is equal to element_2.
*/
int compare (const void *element_1, const void *element_2);

int main (void) {
  
  int *arr_ptr;

  srand((unsigned int) time(NULL));
  
  printf("The program creates an array of 100 elements with elements being random.\n");

  arr_ptr = malloc(sizeof(int) * ARR_SIZE);

  if (arr_ptr == NULL) {
    fprintf(stderr, "[FATAL ERROR] Sufficient Memory Allocation Failed When Calling malloc. Exiting.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < ARR_SIZE; i++) {
    arr_ptr[i] = rand();
  }

  qsort((arr_ptr + 50), 50, sizeof(*(arr_ptr + 0)), compare);

  printf("Index             Element\n"                              \
         "-----             -------\n");

  for (int i = 0; i < ARR_SIZE; i++) {
    printf("%5d\t\t%5d\n", i, arr_ptr[i]);
  }

  free(arr_ptr);
  arr_ptr = NULL;

  return 0;
}

int compare (const void *element_1, const void *element_2) {
  const int *ele_1 = element_1, *ele_2 = element_2;

  if (*ele_1 > *ele_2) {
    return 1;
  } else if (*ele_1 < *ele_2) {
    return -1;
  } else { 
    return 0;
  }
}

