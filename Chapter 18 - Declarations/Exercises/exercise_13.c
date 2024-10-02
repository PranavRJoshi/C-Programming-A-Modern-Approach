// Q. Which of the following declarations are legal? (Assume that PI is a macro that represents 3.14159.)
//      a. char c = 65;
//      b. static int i = 5, j = i * i;
//      c. double d = 2 * PI;
//      d. double angles[] = { 0, PI / 2, PI, 3 * PI / 2 };
// A. Based on my understanding, 
//      a. is legal. char is one byte 'int' like data type. char--which defaults to signed in normal scenario--has the value range from -128 to 127, while unsigned char can store values from 0 to 255.
//      b. is legal. Although it might seem like initialization of j seems to have Undefined behavior since i is initialized in the same line, but as of my understanding, a comma is considered a sequence point, hence the value will be successfully initialized before being utilized by the initializtion of variable j.
//      c. is legal. Assigning PI (which is a macro that represents a double literal) * 2, will result in a value of type double (implicit conversion, check chapter 7).
//      d. is legal. angles is an array of type double, and the values stored will be double, even if it is an integer literal, will be converted to double due to implicit conversion.
//
// Actual Output: Seems like all but b was right. Apparently, initializer must be a compile time constant. This is true, as i is not a constant. And initializing variable j with variable is illegal. Check #45(1) of Chapter's notes.

#include <stdio.h>

#define PI 3.14159

int main (void) {

  char c = 65;
  static int i = 5/*, j = i * i*/;
  double d = 2 * PI;
  double angles[] = { 0, PI / 2, PI, 3 * PI / 2 };

  printf("The value stored in c is: %d\n", c);
  printf("The character stored in c is: %c\n", c);
  printf("The value stored in i is: %d\n", i);
  printf("The value stored in d is: %lf\n", d);
  
  for (int i = 0; i < (int) (sizeof(angles) / sizeof(angles[0])); i++) {
    printf("Array variable angles and its subscript %d has the value: %lf\n", i, angles[i]);
  }

  return 0;
}

