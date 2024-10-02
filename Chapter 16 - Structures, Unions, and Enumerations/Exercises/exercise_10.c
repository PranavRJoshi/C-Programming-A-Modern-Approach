// Q. The following structures are designed to store information about objects on a graphics screen:
//    struct point { int x, y; };
//    struct rectangle { struct point upper_left, lower_right; };
// A point structure stores the x and y coordinates of a point on the screen. A rectangle structure stores the coordinates of the upper left and lower right corners of a rectangle. Write a function that perform the following operations on a rectangle structure r passed as an argument:
//    (a) Compute the area of r.
//    (b) Compute the center of r, returning it a point value. If either the x or y coordinate of the center isn't an integer, store its truncated value in the point structure.
//    (c) Move r by x units in the x direction and y units in the y direction, returning the modified version of r. (x and y are additional arguments to the function.)
//    (d) Determine whether a point p lies within r, returning true or false. (p is an additional argument of type struct point.)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * point: is a structure that has the members x (int), and y (int)
 *        as the coordinates in a 2D plane*/
struct point {
  int x, y;
};

/*
 * rectangle: is a structure that has the members upper_left
 *            and lower_right variable of type struct point.*/
struct rectangle {
  struct point upper_left, lower_right;
};

/*
 * area_of_triangle:  Returns the area of the rectangle whose
 *                    coordinates are stored in the struct rectangle.
*/
int area_of_rectangle (struct rectangle rect);

/*
 * center_of_rectangle: Returns point structure that contains the center of the
 *                      rectangle provided.
*/
struct point center_of_rectangle (struct rectangle rect);

/*
 * move_rectangle:  Returns a rectangle structure that is the modified 
 *                  version of the parameter rect whose x coordinate 
 *                  and y coordinate is added by additional_coord.x 
 *                  and additional_coord.y respectively.
*/ 
struct rectangle move_rectangle(struct rectangle rect, struct point additional_coord);

/*
 * is_inside_rectangle: Checks if the point structure coord is inside 
 *                      the rectangle structure rect. Returns true if 
 *                      it is inside the rectangle, else false.
*/ 
bool is_inside_rectangle (struct rectangle rect, struct point coord);

/*
 * clear_input_stream:  Clears the input buffer or the file that is being read.
 *                      If the character encountered is a new-line character
 *                      or an EOF in file, returns.
*/
void clear_input_stream (void);

int main (void) {

  struct rectangle rect = { .upper_left.x = 0, .lower_right.y = 0 };
  struct point additional_coord;
  struct point check_point;
  struct point center;

  int scanf_return_count = 0;

  int command;

  int area;

  printf("Enter the length and breadth of the rectangle: ");
  for (;;) {
    scanf_return_count = scanf("%d%d", &rect.lower_right.x, &rect.upper_left.y);
    if (scanf_return_count != 2) {
      while (getchar() != '\n') {
        ;
      }
      printf("[ERROR] Insufficient Input Field Provided.\n"     \
             "Enter the length and breadth of the rectangle: ");
      continue;
    }
    scanf_return_count = 0;
    break;
  }

  for (;;) {
    printf("Enter the command for the following actions:\n"                     \
           "              Usage                             Command\n"          \
           "1. Calculate the area of the rectangle.           (a)\n"            \
           "2. Compute the center                             (b)\n"            \
           "3. Move the shape                                 (m)\n"            \
           "3. Check if a point lies inside the rectangle.    (c)\n"            \
           "4. Quit the program.                              (q)\n"            \
           "Enter command: ");
    /* The loop terminates when command holds the non-space character. */
    while (isspace(command = getchar())) {
      ;
    }
    clear_input_stream();
    switch (command) {
      case 'a':
        area = area_of_rectangle(rect);
        printf("[LOG] The area of the rectangle is: %d\n\n\n", area);
        break;
      case 'b':
        center = center_of_rectangle(rect);
        printf("The center of the rectangle is: x = %d and y = %d\n\n\n", center.x, center.y);
        break;
      case 'm':
        printf("Move rectangle by (format x, y): ");
        for (;;) {
          scanf_return_count = scanf("%d,%d", &additional_coord.x, &additional_coord.y);
          if (scanf_return_count != 2) {
            while (getchar() != '\n') {
              ;
            }
            printf("[ERROR] Insufficient/Incorrect Input Field Provided.\n"     \
                   "Enter the additional x coordinate and y coordinate in the format x, y: ");
            continue;
          }
          scanf_return_count = 0;
          break;
        }
        rect = move_rectangle(rect, additional_coord);
        printf("[LOG] The rectangle's new length and breadth is:\n"         \
               "Length: %d\nBreadth: %d\n\n\n", rect.lower_right.x, rect.upper_left.y);
        break;
      case 'c':
        printf("Enter the point to check if it lies inside the rectangle (format x, y): ");
        for (;;) {
          scanf_return_count = scanf("%d,%d", &check_point.x, &check_point.y);
          if (scanf_return_count != 2) {
            while (getchar() != '\n') {
              ;
            }
            printf("[ERROR] Insufficient/Incorrect Input Field Provided.\n"     \
                   "Enter the x coordinate and y coordinate in the format x, y: ");
            continue;
          }
          scanf_return_count = 0;
          break;
        }

        if (is_inside_rectangle(rect, check_point)) {
          printf("[LOG] The point provided is inside the rectangle.\n\n\n");
        } else {
          printf("[LOG] The point provided is not inside the rectangle.\n\n\n");
        }
        break;
      case 'q':
        exit(EXIT_SUCCESS);
      default:
        printf("[ERROR] Invalid command entered!\n\n\n");
    }
  }

  return 0;
}

int area_of_rectangle (struct rectangle r) {
  return r.lower_right.x * r.upper_left.y;
}

struct point center_of_rectangle (struct rectangle r) {
  struct point temp;

  temp.x = (int) (r.lower_right.x / 2);
  temp.y = (int) (r.upper_left.y  / 2);

  return temp;
}

struct rectangle move_rectangle(struct rectangle rect, struct point add_coord) {
  rect.lower_right.x  += add_coord.x;
  rect.upper_left.y   += add_coord.y;

  return rect;
}

bool is_inside_rectangle (struct rectangle rect, struct point coord) {
  return  coord.x >= rect.upper_left.x  && coord.x <= rect.lower_right.x  ?     \
          coord.y >= rect.lower_right.y && coord.y <= rect.upper_left.y   ?     \
          true : false : false;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

