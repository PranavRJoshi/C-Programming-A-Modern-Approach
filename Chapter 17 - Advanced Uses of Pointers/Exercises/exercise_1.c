// Q. Having to check the return value of malloc (or any other memory allocation function) each time we call it can be annoyance. Write a function named my_malloc that serves as a "wrapper" for malloc. When we call my_malloc and ask it to allocate n bytes, it in turns call malloc, tests to make sure that malloc doesn't return a null pointer, and then returns the pointer from malloc. Have my_malloc print an error message and terminate the program if malloc returns a null pointer.

#include <stdio.h>
#include <stdlib.h>


#define MALLOC_ERR(size_t_bytes)          \
printf("[ERROR] Failed to allocate %zu bytes of memory on\nfile: %s\nline: %d\n", size_t_bytes, __FILE__, __LINE__)

/*
 * my_malloc: Returns a pointer/address that can store bytes byte of data
 *            when successful. Otherwise, prints an error message and 
 *            terminates the program.
*/
void *my_malloc (size_t bytes);

void clear_input_stream (void);

int main (void) {

  int *test_arr;
  size_t arr_size;
  int scanf_return_count = 0;

  for (;;) {
    printf("Enter the size of the array to store the integer elements: ");
    if ((scanf_return_count = scanf("%zu", &arr_size)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  test_arr = my_malloc(arr_size);

  for (size_t i = 0; i < arr_size; i++) {
    for (;;) {
      printf("Enter element %zu: ", i);
      if ((scanf_return_count = scanf("%d", (test_arr + i))) != 1) {
        fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
        clear_input_stream();
        continue;
      }
      scanf_return_count = 0;
      clear_input_stream();
      break;
    }
  }

  printf("The array contains the following elements: \n");
  for (size_t i = 0; i < arr_size; i++) {
    printf("Element %zu: %d\n", i, *(test_arr + i));
  }

  return 0;
}

void *my_malloc (const size_t bytes) {
  void *alloc_p;

  alloc_p = malloc(bytes);

  if (alloc_p == NULL) {
    MALLOC_ERR(bytes);
    exit(EXIT_FAILURE);
  }

  return alloc_p;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

