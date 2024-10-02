// Q. Write the following functions. (The color structure is defined in Exercise 8:)
//    (a) struct color make_color(int red, int green, int blue);
// Returns a color structure containing the specified red, green, and blue values. If any argument is less than zero, the corresponding member of the structure will contain zero instead. 
// If any argument is greater than 255, the corresponding member of the structure will contain 255.
//    (b) int getRed(struct color c);
// Returns the value of c's red member.
//    (c) bool equal_color(struct color color1, struct color color2);
// Returns true if the corresponding members of color1 and color2 are equal.
//    (d) struct color brighter(struct color c);
// Returns a color structure that represents a brighter version of the color c. The structure is identical to c, except that each member has been divided by 0.7 (with the result truncated to an integer). However, there are three special cases: 
//    (1) If all members of c are zero, the function returns a color whose members all have the value 3. 
//    (2) If any member of c is greater than 0 but less than 3, it is replaced by 3 before division before division by 0.7.
//    (3) If dividing by 0.7 causes a member to exceed 255, it is reduced to 255.
//    
//    (e) struct color darker(struct color c);
// Returns a color structure that represents a darker version of the color c. The structure is identical to c, except that each member has been multiplied by 0.7 (with the result truncated to an integer).

#include <stdio.h>
#include <stdbool.h>

/*
 * color: A structure with members red (int), green (int),
 *        and blue (int).
*/
struct color {
  int red;
  int green;
  int blue;
};

/*
 * make_color:  Returns a color structure containing the specified red, green, 
 *              and blue values. If any argument is less than zero, the corresponding 
 *              member of the structure will contain zero instead. If any argument is 
 *              greater than 255, the corresponding member of the structure will contain 255. 
*/
struct color make_color (int red, int green, int blue);

/* getRed:  Returns the value of c's red member.
*/
int getRed (struct color c);

/* equal_color: Returns true if the corresponding members
 *              of color1 and color2 are equal.
*/
bool equal_color (struct color color1, struct color color2);

/* brighter:  Returns a color structure that represents a 
 *            brighter version of the color c. The structure 
 *            is identical to c, except that each member has been 
 *            divided by 0.7 (with the result truncated to an integer). 
 *            However, there are three special cases: 
 *            (1) If all members of c are zero, the function returns a color whose members all have the value 3. 
 *            (2) If any member of c is greater than 0 but less than 3, it is replaced by 3 before division before division by 0.7.
 *            (3) If dividing by 0.7 causes a member to exceed 255, it is reduced to 255.
*/ 
struct color brighter (struct color c);

/* darker:  Returns a color structure that represents a 
 *          darker version of the color c. The structure 
 *          is identical to c, except that each member has been 
 *          multiplied by 0.7 (with the result truncated to an integer).
*/ 
struct color darker (struct color c);

/*
 * clear_imput_stream:  clears the standard input stream. will also work
 *                      for files that have EOF as the last character.
*/
void clear_input_stream (void);

int main (void) {

  int red, green, blue;
  int scanf_return;

  struct color c1, c2;

  for (;;) {
    printf("Enter the Red, Green, and Blue value for the first color: ");
    scanf_return = scanf("%d%d%d", &red, &green, &blue);
    if (scanf_return != 3) {
      clear_input_stream();
      printf("[ERROR] Insufficient Input Provided.\nTry Again\n");
      continue;
    }
    scanf_return = 0;
    break;
  }

  c1 = make_color(red, green, blue);

  for (;;) {
    printf("Enter the Red, Green, and Blue value for the first color: ");
    scanf_return = scanf("%d%d%d", &red, &green, &blue);
    if (scanf_return != 3) {
      clear_input_stream();
      printf("[ERROR] Insufficient Input Provided.\nTry Again: ");
      continue;
    }
    scanf_return = 0;
    break;
  }

  c2 = make_color(red, green, blue);

  printf("The value of red in color1 and color2 is: %d and %d respectively.\n", getRed(c1), getRed(c2));

  bool is_same_color = equal_color(c1, c2);

  if (is_same_color) {
    printf("The entered colors are the same.\n");
  } else {
    printf("The entered colors are different.\n");
  }

  struct color brighter_color;
  brighter_color = brighter(c1);
  printf("The brighter color version for color 1 is:\n"     \
         "Red = %d\nGreen = %d\nBlue = %d\n", brighter_color.red, brighter_color.green, brighter_color.blue);
  brighter_color = brighter(c2);
  printf("The brighter color version for color 2 is:\n"     \
         "Red = %d\nGreen = %d\nBlue = %d\n", brighter_color.red, brighter_color.green, brighter_color.blue);

  struct color darker_color;
  darker_color = darker(c1);
  printf("The darker color version for color 1 is:\n"     \
         "Red = %d\nGreen = %d\nBlue = %d\n", darker_color.red, darker_color.green, darker_color.blue);
  darker_color = darker(c2);
  printf("The darker color version for color 2 is:\n"     \
         "Red = %d\nGreen = %d\nBlue = %d\n", darker_color.red, darker_color.green, darker_color.blue);

  return 0;
}

struct color make_color (int red, int green, int blue) {
  struct color temp;

  temp.red    = red   < 0 ? 0 : red   > 255 ? 255 : red;
  temp.green  = green < 0 ? 0 : green > 255 ? 255 : green;
  temp.blue   = blue  < 0 ? 0 : blue  > 255 ? 255 : blue;

  return temp;
}

int getRed (struct color c) {
  return c.red;
}

bool equal_color (struct color c1, struct color c2) {
  if (c1.red == c2.red) {
    if (c1.green == c2.green) {
      if (c1.blue == c2.blue) {
        return true;
      }
    }
  }
  return false;
}

struct color brighter (struct color c) {
  if (c.red == 0 && c.green == 0 && c.blue == 0) {
    c.red   = 3;
    c.green = 3;
    c.blue  = 3;
    return c;
  } 

  if (c.red >= 3 && c.green >= 3 && c.blue >= 3) {
    c.red   = c.red   / 0.7;
    c.green = c.green / 0.7;
    c.blue  = c.blue  / 0.7;

    if (c.red > 255) {
      c.red = 255;
    }

    if (c.green > 255) {
      c.green = 255;
    }

    if (c.blue > 255) {
      c.blue = 255;
    }

    return c;
  }

  if (c.red > 0 && c.red < 3) {
    c.red = 3;
    c.red = c.red / 0.7;
  } else {
    c.red = c.red / 0.7;

    if (c.red > 255) {
      c.red = 255;
    }
  }

  if (c.green > 0 && c.green < 3) {
    c.green = 3;
    c.green = c.green / 0.7;
  } else {
    c.green = c.green / 0.7;

    if (c.green > 255) {
      c.green = 255;
    }
  }

  if (c.blue > 0 && c.blue < 3) {
    c.blue = 3;
    c.blue = c.blue / 0.7;
  } else {
    c.blue = c.blue / 0.7;

    if (c.blue > 255) {
      c.blue = 255;
    }
  }

  return c;
}

struct color darker (struct color c) {
  c.red   = c.red   * 0.7;
  c.green = c.green * 0.7;
  c.blue  = c.blue  * 0.7;

  return c;
}

void clear_input_stream (void) {
  int ch = getchar();
  
  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

