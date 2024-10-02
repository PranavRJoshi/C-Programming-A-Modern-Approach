// Q. Let shape be the structure tag declared in Exercise 13. Write functions that perform the following operations on a shape structure s passed as an argument:
//    a. Compute the area of s.
//    b. Move s by x units in x direction and y units in the y direction, returning the modified version of s. (x and y are additional arguments to the function.)
//    c. Scale s by a factor of c (a double value), returning the modified version of s. (c is an additional argument to the function.)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define PI 3.141592

struct point {
  int x, y;
};

struct shape {
  enum { RECTANGLE, CIRCLE } shape_kind;
  struct point center;
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
};

/*
 * calculate_area:  Returns the area of the shape
 *                  that is defined in the structure shape s.
 *                  Return type of double as area of circle is not 
 *                  usually an integer.
*/
double calculate_area (struct shape s);

/*
 * move_shape:  Takes a structure shape and moves x in the horizontal 
 *              direction and y in the vertical direction. Changes are 
 *              applied to the point structure defined inside the structure 
 *              shape. Returns the modified structure. 
*/
struct shape move_shape (struct shape s, int x, int y);

/*
 * scale_shape: Takes a structure shape and scales it by a factor of scale_factor.
 *              If the shape is rectangle, factor affects both height and width.
 *              If the shape is circle, factor affects only the radius.
*/
struct shape scale_shape (struct shape s, double scale_factor);

/*
 * print_shape: Prints the members of the structure shape variable.
 *              It automatically picks the shape based on the enum 
 *              defined.
*/
void print_shape (struct shape s);

/*
 * clear_input_stream:  Clears the input stream.
*/
void clear_input_stream (void);

int main (void) {

  struct shape s;
  
  int command;
  int shape_option = 0;
  int scanf_return_count = 0;

  double shape_area = 0.0;
  struct point shift;
  double scale = 0.0;

  for (;;) {
    printf("A program that provides the listed functionality for either rectangle or circle:\n"       \
           "          Usage                   Commands\n"                                             \
           "1. Initialize the shape             (i)\n"                                                \
           "2. Calculate the area               (a)\n"                                                \
           "3. Move the shape                   (m)\n"                                                \
           "4. Scale the shape                  (s)\n"                                                \
           "5. View the current shape detail    (v)\n"                                                \
           "6. Quit the program                 (q)\n"                                                \
           "Enter your command: ");
    while (isspace(command = getchar())) {
      ;
    }
    
    switch (command) {
      case 'i':
        for (;;) {
          printf("Enter the necessary parameters for the shape:\n"                    \
                 "Press 1 for rectangle.\n"                                           \
                 "Press 2 for circle.\n");
          if ((scanf_return_count = scanf("%d", &shape_option)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          } else {
            if (shape_option != 1 && shape_option != 2) {
              fprintf(stderr, "[ERROR] Invalid Option Picked.\n");
              clear_input_stream();
              continue;
            }
          }
          clear_input_stream();
          scanf_return_count = 0;
          break;
        }
        if (shape_option == 1) {
          s.shape_kind = RECTANGLE;
          for (;;) {
            printf("Enter the center (format (x y)): ");
            if ((scanf_return_count = scanf("%d%d", &s.center.x, &s.center.y)) != 2) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            clear_input_stream();
            scanf_return_count = 0;
            break;
          }
          for (;;) {
            printf("Enter the length and breadth (format (l b)): ");
            if ((scanf_return_count = scanf("%d%d", &s.u.rectangle.height, &s.u.rectangle.width)) != 2) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            scanf_return_count = 0;
            break;
          }
        }

        if (shape_option == 2) {
          s.shape_kind = CIRCLE;
          for (;;) {
            printf("Enter the center (format (x y)): ");
            if ((scanf_return_count = scanf("%d%d", &s.center.x, &s.center.y)) != 2) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            clear_input_stream();
            scanf_return_count = 0;
            break;
          }
          for (;;) {
            printf("Enter the radius: ");
            if ((scanf_return_count = scanf("%d", &s.u.circle.radius)) != 1) {
              fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
              clear_input_stream();
              continue;
            }
            scanf_return_count = 0;
            break;
          }
        }
        break;
      case 'a':
        shape_area = calculate_area(s);
        printf("The area of the shape is: %g\n\n\n", shape_area);
        break;
      case 'm':
        for (;;) {
          printf("Enter the x and y coordinates to move the shape by (format (x y)): ");
          if ((scanf_return_count = scanf("%d%d", &shift.x, &shift.y)) != 2) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          break;
        }
        s = move_shape(s, shift.x, shift.y);
        print_shape(s);
        break;
      case 's':
        for (;;) {
          printf("Enter the scale factor: ");
          if ((scanf_return_count = scanf("%lf", &scale)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          break;
        }
        s = scale_shape(s, scale);
        print_shape(s);
        break;
      case 'v':
        print_shape(s);
        break;
      case 'q':
        exit(EXIT_FAILURE);
      default:
        fprintf(stderr, "[ERROR] Invalid Command Entered!\n");
    }

    while ((command = getchar()) != '\n') {
      ;
    }
  }
  return 0;
}

double calculate_area (struct shape s) {
  double area = 0.0;

  if (s.shape_kind == RECTANGLE) {
    area = s.u.rectangle.height * s.u.rectangle.width;
    return area;
  } else if (s.shape_kind == CIRCLE) {
    area = PI * s.u.circle.radius * s.u.circle.radius;
    return area;
  } else {
    fprintf(stderr, "[FATAL ERROR] No shape defined.\n");
    exit(EXIT_FAILURE);
  }
}

struct shape move_shape (struct shape s, int x, int y) {
  if (s.shape_kind == RECTANGLE || s.shape_kind == CIRCLE) {
    s.center.x += x;
    s.center.y += y;
    return s;
  } else {
    fprintf(stderr, "[FATAL ERROR] No shape defined.\n");
    exit(EXIT_FAILURE);
  }
}

struct shape scale_shape (struct shape s, double scale_factor) {
  if (s.shape_kind == RECTANGLE) {
    s.u.rectangle.width  = (int) s.u.rectangle.width  * scale_factor;
    s.u.rectangle.height = (int) s.u.rectangle.height * scale_factor;
    return s;
  } else if (s.shape_kind == CIRCLE) {
    s.u.circle.radius = (int) s.u.circle.radius * scale_factor;
    return s;
  } else {
    fprintf(stderr, "[FATAL ERROR] No shape defined.\n");
    exit(EXIT_FAILURE);
  }
}

void print_shape (struct shape s) {
  if (s.shape_kind == RECTANGLE) {
    printf("The information about the rectangle is: \n"                                                         \
           "Center (x, y): %d, %d\n"                                                                            \
           "Height: %d\nWidth: %d\n\n\n", s.center.x, s.center.y, s.u.rectangle.height, s.u.rectangle.width);
  } else if (s.shape_kind == CIRCLE) {
    printf("The information about the circle is: \n"                                                         \
           "Center (x, y): %d, %d\n"                                                                            \
           "Radius: %d\n\n\n", s.center.x, s.center.y, s.u.circle.radius);
  } else {
    fprintf(stderr, "[FATAL ERROR] No shape defined.\n");
    exit(EXIT_FAILURE);
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

