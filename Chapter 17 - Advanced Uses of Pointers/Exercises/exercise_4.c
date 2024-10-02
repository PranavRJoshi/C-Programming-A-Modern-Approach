// Q. Suppose that the following declaration are in effect:
//    struct point { int x, y; };
//    struct rectangle { struct point upper_left, lower_right };
//    struct rectangle *p;
// Assume that we want p to point to a rectangle structure whose upper left corner is at (10, 25) and whose lower right corner is at (20, 15). Write a series of statements that allocate such a structure and initialize it as indicated.

#include <stdio.h>
#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

/*
 * initialize_rectangle:  Returns a pointer to a rectangle structure which has the 
 *                        member upper_left and lower_right initialized as provided
 *                        through the arguments upper_left and lower_right respectively.
*/
struct rectangle *initialize_rectangle (struct point upper_left, struct point lower_right);

void clear_input_stream (void);

int main (void) {

  struct rectangle *p;
  struct point ul, lr;

  int scanf_return_count = 0;

  for (;;) {
    printf("Enter the coordinates for the upper left corner (format: x, y): ");
    if ((scanf_return_count = scanf("%d,%d", &ul.x, &ul.y)) != 2) {
      fprintf(stderr, "[ERROR] Insufficient Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }
  
  for (;;) {
    printf("Enter the coordinates for the lower right corner (format: x, y): ");
    if ((scanf_return_count = scanf("%d,%d", &lr.x, &lr.y)) != 2) {
      fprintf(stderr, "[ERROR] Insufficient Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  p = initialize_rectangle(ul, lr);

  printf("The rectangle has the following property:\n"            \
         "Upper Left Coordinate   : %d, %d\n"                     \
         "Lower Right Coordinates : %d, %d\n", p->upper_left.x, p->upper_left.y, p->lower_right.x, p->lower_right.y);

  return 0;
}

struct rectangle *initialize_rectangle (struct point ul, struct point lr) {
  struct rectangle *temp_rect;
  temp_rect = malloc(sizeof(struct rectangle));
  
  if (temp_rect == NULL) {
    fprintf(stderr, "[ERROR] Failed to Allocate Memory in function: %s", __func__);
    exit(EXIT_FAILURE);
  }

  temp_rect->upper_left   = ul;
  temp_rect->lower_right  = lr;

  return temp_rect;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

