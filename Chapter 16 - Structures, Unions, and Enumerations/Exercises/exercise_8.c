// Q. Let color be the following structure:
//    struct color {
//      int red;
//      int green;
//      int blue;
//    };
//    
//    (a) Write a declaration for a const variable named MAGNETA of type struct color whose members have the values 255, 0, and 255 respectively.
//    (b) (C99) Repeat part (a), but use a designated initializer that doesn't specify the value of green, allowing it to default to 0.

#include <stdio.h>

/*
 * color: A structure that has the members red (int), green (int),
 *        and blue (int).
*/
struct color {
  int red;
  int green;
  int blue;
};

int main (void) {

  const struct color MAGNETA      = { 255, 0, 255 };

  const struct color MAGNETA_C99  = { .red = 255, .blue = 255 };

  printf("For the first part, the primary colors defined for MAGNETA is:\n"                 \
         "Red = %d\nGreen = %d\nBlue = %d\n\n", MAGNETA.red, MAGNETA.green, MAGNETA.blue);

  printf("For the second part, the primary colors defined for MAGNETA_C99 is:\n"            \
         "Red = %d\nGreen = %d\nBlue = %d\n\n", MAGNETA_C99.red, MAGNETA_C99.green, MAGNETA_C99.blue);
  
  return 0;
}
