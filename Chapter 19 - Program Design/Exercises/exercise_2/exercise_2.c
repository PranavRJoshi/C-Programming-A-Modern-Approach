#include <stdio.h>
#include "stack.h"

void clear_input_buffer (void);

// Function written for understanding purpose.
// enum scanf_type { INT, CHAR, DOUBLE };
// int my_scanf (void *data_ptr, enum scanf_type type);

int main (void) {

  printf("A simple stack interface.\n");

  int scanf_return_count = 0;

  int push_item;

  for (;;) {
    printf("Enter the item to push to stack: ");
    if ((scanf_return_count = scanf("%d", &push_item)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
      scanf_return_count = 0;
      clear_input_buffer();
      continue;
    }
    scanf_return_count = 0;
    clear_input_buffer();
    break;
  }

  push(push_item);

  if (is_empty()) {
    printf("[LOG] Stack is currently empty.\n");
  } else {
    printf("[LOG] Stack is currently not empty.\n");
  }

  int pop_item;

  pop_item = pop();

  printf("[LOG] The popped item is: %d\n", pop_item);

  make_empty();

  return 0;
}

void clear_input_buffer (void) {
  while (getchar() != '\n') {
    ;
  }
}

/* A test function. Isn't used, for now. */
// int my_scanf (void *data_ptr, enum scanf_type type) {
//   int scanf_return_count = 0;
//   char *conversion_specifier;
//   switch (type) {
//     case INT: 
//       conversion_specifier = "%d";
//       data_ptr = (int *) data_ptr;
//       break;
//     case CHAR: 
//       conversion_specifier = " %c";   /* a leading space to ensure that no white-space is taken as input */
//       data_ptr = (char *) data_ptr;
//       break;
//     case DOUBLE: 
//       conversion_specifier = "%d";
//       data_ptr = (double *) data_ptr;
//       break;
//     default:
//       fprintf(stderr, "[ERROR] Invalid type provided. Returning.\n");
//       return 0;
//   }
//
//   for (;;) {
//     printf("Enter the value: ");
//     if ((scanf_return_count = scanf(conversion_specifier, data_ptr)) != 1) {
//       fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
//       scanf_return_count = 0;
//       clear_input_buffer();
//       continue;
//     }
//     clear_input_buffer();
//     break;
//   }
//   return scanf_return_count;
// }

