// Q. The following function, which computes the area of a triangle, contains two errors. Locate the errors and show how to fix them. (Hint: There are no errors in the formula.)
//    double triangle_area (double base, height)
//    double product;
//    {
//      product = base * height;
//      return product / 2;
//    }

// A. Some problems that i can detect are:
//    1. the type of height is not defined, the compiler defaults the type of height to int
//    2. There is a declaration for the parameter product, but the function does not have a parameter named product.

#include <stdio.h>

double triangle_area (base, height) double base; double height; {
  double product;

  product = base * height;

  return product / 2;
}

int main (void) {

  double base, height;
  base = height = 0.0;
  double area = 0.0;

  printf("Enter the base of the triangle: ");
  scanf("%lf", &base);
  
  printf("Enter the height of the triangle: ");
  scanf("%lf", &height);

  area = triangle_area(base, height);

  printf("The area of the triangle is: %.2lf\n", area);

  return 0;
}

