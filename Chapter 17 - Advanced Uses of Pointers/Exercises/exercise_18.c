// Q. Modify the compare_parts function so that parts are sorted with their numbers in descending order.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* For demonstration purposes. Actual structure contains name, and on_hand members as well. */
struct part {
  int number;
};

/*
 * compare_parts: comparison function that sorts the list in the descending order.
*/
int compare_parts (const void *p, const void *q);

void clear_input_stream (void);

int main (void) {

  srand((unsigned int) time(NULL));
  
  int part_size;

  int scanf_return_count = 0;

  struct part *part_arr_ptr;

  for (;;) {
    printf("How many parts do you want to allocate: ");
    if ((scanf_return_count = scanf("%d", &part_size)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    if (part_size <= 0) {
      fprintf(stderr, "[WARN] Part size cannot be zero or negative. Try Again.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  part_arr_ptr = malloc(sizeof(struct part) * part_size);
  
  if (part_arr_ptr == NULL) {
    fprintf(stderr, "[FATAL ERROR] Cannot Allocate Sufficient Memory. Exiting.\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Inserting random numbers for part's member (int number).\n");

  for (int i = 0; i < part_size; i++) {
    (part_arr_ptr + i)->number = rand();
  }

  qsort(part_arr_ptr, part_size, sizeof(struct part), compare_parts);

  printf("Index         Address           Member (number)\n"            \
         "-----         -------           ---------------\n");

  for (int i = 0; i < part_size; i++) {
    printf("%-5d     %p          %5d\n", i, (void *) (part_arr_ptr + i), (part_arr_ptr + i)->number);
  }

  free(part_arr_ptr);
  part_arr_ptr = NULL;
  
  return 0;
}

int compare_parts (const void *p, const void *q) {
  const struct part *p1 = p;
  const struct part *q1 = q;

  if (p1->number > q1->number) {
    return -1;
  } else if (p1->number == q1->number) {
    return 0;
  } else {
    return 1;
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

