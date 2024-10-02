// Q. Assume that the fraction structure contains two members: numerator and denominator (both of type int). Write functions that perform the following operations on fractions:
//    (a) Reduce the fraction f to lowest terms. Hint: To reduce a fraction to lowest terms, first compute the greatest common divisor (GCD) of the numerator and denominator by the GCD.
//    (b) Add the fractions f1 and f2.
//    (c) Subtract the fraction f2 from the fraction f1.
//    (d) Multiply the fractions f1 and f2.
//    (e) Divide the fraction f1 by the fraction f2.
//
// The fractions f, f1, and f2 will be arguments of type struct fraction; each function will return a value of type struct fraction. The fractions returned by the functions in parts (b)-(e) should be reduced to the lowest terms. Hint: You may use the function from part (a) to help write the functions in parts (b)-(e).

#include <stdio.h>

struct fraction {
  int numerator;
  int denominator;
};

/*
 * reduce_fraction: Takes the parameter "fraction_to_reduce" and uses the GCD 
 *                  to generate a fraction that can be presented in its lowest terms.
 *                  Returns a reduced fraction structure.
*/
struct fraction reduce_fraction (struct fraction fraction_to_reduce);

/*
 * add_fractions: takes two fractions: fraction_1 and fraction_2, and returns a fraction
 *                structure that is the sum of two fractions. The returned value is in 
 *                the reduced form.
*/
struct fraction add_fractions (struct fraction fraction_1, struct fraction fraction_2);

/*
 * subtract_fractions:  takes two fractions: fraction_1 and fraction_2, and returns a 
 *                      fraction structure that is the subtraction of fraction_2 from 
 *                      fraction_1. The returned value is in the reduced form.
*/
struct fraction subtract_fractions (struct fraction fraction_1, struct fraction fraction_2);

/*
 * multiply_fractions:  takes two fractions: fraction_1 and fraction_2, and returns a
 *                      fraction structure that is the multiplication of two fractions.
 *                      The returned value is in the reduced form.
*/
struct fraction multiply_fractions (struct fraction fraction_1, struct fraction fraction_2);

/*
 * divide_fractions:  takes two fractions: fraction_1 and fraction_2, and returns a fraction
 *                    structure that is the division of fraction_1 by fraction_2. The returned
 *                    value is in the reduced form.
*/
struct fraction divide_fractions (struct fraction fraction_1, struct fraction fraction_2);

int main (void) {
  
  struct fraction frac_1, frac_2;

  printf("Enter the numerator and denominator for the first fraction (in the format n/d): ");
  while (scanf("%d/%d", &frac_1.numerator, &frac_1.denominator) != 2) {
    int ch;
    while ((ch = getchar()) != '\n') {
      ;
    }
    printf("[ERROR] Not enough input field provided.\nTry Again: ");
  }

  printf("Enter the numerator and denominator for the second fraction (in the format n/d): ");
  while (scanf("%d/%d", &frac_2.numerator, &frac_2.denominator) != 2) {
    int ch;
    while ((ch = getchar()) != '\n') {
      ;
    }
    printf("[ERROR] Not enough input field provided.\nTry Again: ");
  }

  printf("\n\nThe following operations are performed.\n");
  struct fraction reduced_frac_1, reduced_frac_2;
  reduced_frac_1 = reduce_fraction(frac_1);
  reduced_frac_2 = reduce_fraction(frac_2);
  printf("Reduced form of the first fraction is: %d/%d\n", reduced_frac_1.numerator, reduced_frac_1.denominator);
  printf("Reduced form of the second fraction is: %d/%d\n", reduced_frac_2.numerator, reduced_frac_2.denominator);
  
  struct fraction sum_frac, diff_frac, mul_frac, div_frac;
  sum_frac  = add_fractions(frac_1, frac_2);
  diff_frac = subtract_fractions(frac_1, frac_2);
  mul_frac  = multiply_fractions(frac_1, frac_2);
  div_frac  = divide_fractions(frac_1, frac_2);
  printf("The sum of first fraction and second fraction is: %d/%d\n", sum_frac.numerator, sum_frac.denominator);
  printf("The subtraction of second fraction from first fraction is: %d/%d\n", diff_frac.numerator, diff_frac.denominator);
  printf("The multiplication of first fraction and second fraction is: %d/%d\n", mul_frac.numerator, mul_frac.denominator);
  printf("The division of first fraction by second fraction is: %d/%d\n", div_frac.numerator, div_frac.denominator);

  return 0;
}

struct fraction reduce_fraction (struct fraction f) {
  int remainder;
  int temp_num, temp_denom;

  struct fraction temp;

  temp_num = f.numerator, temp_denom = f.denominator;

  // compute the GCD, which is divides the numerator and denominator to get the reduced fraction
  // the GCD is stored in temp_num
  while (temp_denom != 0) {
    remainder   = temp_num % temp_denom;
    temp_num    = temp_denom;
    temp_denom  = remainder;
  }

  temp.numerator    = f.numerator   / temp_num;
  temp.denominator  = f.denominator / temp_num;

  return temp;
}

struct fraction add_fractions (struct fraction f1, struct fraction f2) {
  struct fraction temp;

  temp.numerator    = (f1.numerator   * f2.denominator) + (f2.numerator * f1.denominator);
  temp.denominator  = (f1.denominator * f2.denominator);

  return reduce_fraction(temp);
}

struct fraction subtract_fractions (struct fraction f1, struct fraction f2) {
  struct fraction temp;

  temp.numerator    = (f1.numerator   * f2.denominator) - (f2.numerator * f1.denominator);
  temp.denominator  = (f1.denominator * f2.denominator);

  return reduce_fraction(temp);
}

struct fraction multiply_fractions (struct fraction f1, struct fraction f2) {
  struct fraction temp;

  temp.numerator    = f1.numerator    * f2.numerator;
  temp.denominator  = f1.denominator  * f2.denominator;

  return reduce_fraction(temp);
}

struct fraction divide_fractions (struct fraction f1, struct fraction f2) {
  struct fraction temp;
  
  temp.numerator    = f1.numerator    * f2.denominator;
  temp.denominator  = f1.denominator  * f2.numerator;

  return reduce_fraction(temp);
}

