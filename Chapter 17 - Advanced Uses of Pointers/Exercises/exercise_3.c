// Q. Write the following function:
//    int *create_array(int n, int initial_value);
// The function should return a pointer to a dynamically allocated int array with n members, each of which is initialized to initial_value. The return value should be NULL if the array can't be allocated.

#include <stdio.h>
#include <stdlib.h>

/*
 * create_array:  Creates an array of n elements, each element is initialized 
 *                with the value initial_value. If the cannot be created, returns 
 *                NULL.
*/
int *create_array (int n, int initial_value);

void clear_input_stream (void);

int main (void) {
  
  int arr_size, arr_init_value;
  int scanf_return_count = 0;
  int *arr_ptr;

  for (;;) {
    printf("Enter the array size and the initial value: ");
    if ((scanf_return_count = scanf("%d%d", &arr_size, &arr_init_value)) != 2) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    if (arr_size <= 0) {
      fprintf(stderr, "[FATAL ERROR] Cannot create an array of negatve size. Try Again.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  arr_ptr = create_array(arr_size, arr_init_value);

  if (arr_ptr == NULL) {
    fprintf(stderr, "[ERROR] Failed to Allocate Memory for an Integer Array of size %d\n.", arr_size);
  } else {
    printf("[SUCCESS] Created an Array of size %d.\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
      printf("Element %d has the value: %d\n", i, arr_ptr[i]);
    }
  }

  return 0;
}

int *create_array (int n, int init_value) {
  int *temp_arr;
  temp_arr = malloc(sizeof(int) * n);

  if(temp_arr == NULL) {
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    *(temp_arr + i) = init_value; 
  }

  return temp_arr;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

