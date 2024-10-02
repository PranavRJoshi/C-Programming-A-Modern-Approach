// Q. Suppose that s is the following structure (point is a structure tag declared in Exercise 10):
//    NOTE: From previous question:
//    struct point {
//      int x, y;  
//    };
//
//    struct shape {
//      int shape_kind;         /* RECTANGLE or CIRCLE */
//      struct point center;    /* coordinates of center */
//      union {
//        struct {
//          int height, width;
//        } rectangle;
//        struct {
//          int radius;
//        } circle;
//      } u;
//    } s;
// If the value of shape_kind is RECTANGlE, the height and width members store the dimensions of a rectangle. If the value of shape_kind is CIRCLE, the radius member stores the radius of a circle. Indicate which of the following statements are legal, and show how to repair the ones that aren't:
//    a. s.shape_kind = RECTANGLE;
//    b. s.center.x = 10;
//    c. s.height = 25;
//    d. s.u.rectangle.width = 8;
//    e. s.u.circle = 5;
//    f. s.u.radius = 5;
//
// My Answer:
//  For:
//    a. The statement isn't legal as the type of shape_kind is integer, not enum. To make the statement legal, we need to define shape_kind as:
//      enum { RECTANGLE, CIRCLE } shape_kind;
//    b. The statements are indeed legal as it accesses the member x of the structure center of tag point, of the structure s of tag shape.
//    c. The statement isn't legal, as it is trying to access the member height of the structure s of tag shape. But height is not a member of the structure shape, but rather a member of the structure variable rectangle which is embedded inside the union variable u. To make the statement legal, we need to state it as:
//      s.u.rectangle.height = 25;
//    d. The statement is indeed legal.
//    e. The statement is not legal as there is no speicification on the member for the structure variable circle. The correct statement will be:
//      s.u.circle.radius = 5;
//    f. The statement is not legal as radius is not a member of the union variable u, but rather a member of the structure variable circle embedded inside the union variable u.

#include <stdio.h>

struct point {
  int x, y;
};

struct shape {
  // int shape_kind;  // Not legal, but need to have a separate macro called RECTANGLE and CIRCLE
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
} s1, s2;


/*
 * print_shape: Prints the structure of tag shape.
 *              Checks if the structure holds the content for 
 *              RECTANGLE or CIRCLE before printing.
*/
void print_shape (struct shape s);

int main (void) {

  s1.shape_kind = RECTANGLE;
  s2.shape_kind = CIRCLE;
  
  if (s1.shape_kind == RECTANGLE) {
    s1.center.x           = 0;
    // s1.height = 25;  // Illegal: "No member named 'height' in struct 'shape'"
    s1.u.rectangle.width  = 8;
  }

  if (s2.shape_kind == CIRCLE) {
    // s2.u.circle = 5; // Illegal: "Assigning to 'struct (unnamed)' from incompatible type 'int'"
    // s2.u.radius = 5;  // Illegal: "No member named 'radius' in union ..."
    s2.u.circle.radius    = 5;
  }

  print_shape(s1);
  print_shape(s2);

  return 0;
}

void print_shape (struct shape s) {
  if (s.shape_kind == RECTANGLE) {
    printf("The center of the Rectangle is: \n"                                           \
           "x = %d\ny = %d\n", s.center.x, s.center.y);
    printf("The height and the width of the Rectangle is: \n"                             \
           "height = %d\nwidth = %d\n\n", s.u.rectangle.height, s.u.rectangle.width);
  } else if (s.shape_kind == CIRCLE) {
    printf("The center of the Circle is: \n"                                           \
           "x = %d\ny = %d\n", s.center.x, s.center.y);
    printf("The Radius of the Circle is: \n"                                           \
           "radius = %d\n\n", s.u.circle.radius);
  } else {
    fprintf(stderr, "[FATAL ERROR] The shape_kind for the provided structure is not defined.\n");
  }
}

