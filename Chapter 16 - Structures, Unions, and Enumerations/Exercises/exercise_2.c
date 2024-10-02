// Q. (a) Declare a structure variables named c1, c2, and c3, each having members real and imaginary of type double.
//    (b) Modify the declaration in part (a) so that c1's members initially have the values 0.0 and 1.0, while c2's members are 1.0 and 0.0 initially. (c3 is not initialized.)
//    (c) Write statements that copy the members of c2 into c1. Can this be done in one statement, or does it require two?
//    (d) Write statements that add the corresponding members of c1 and c2, storing the result in c3.
//
// My answers:
//    (a) We can declare (and define) a struct variable in one of three ways:
//        1. Defining struct without any structure tag:
//            struct {
//              double real;
//              double imaginary;
//            } c1, c2, c3;
//        2. Defining struct along with a structure tag:
//            struct complex_number {
//              double real;
//              double imaginary;
//            } c1, c2, c3;
//        3. Defining a type of structure using typedef:
//            typedef struct {
//              double real;
//              double imaginary;
//            } complex_number;
//    1 is not really a good practice as if we later define another structure (without a tag) with similar members, this won't change the fact that the compiler will treat those two structures are different "types".
//    2 and 3 are preferred practices as it allows the programmer to create multiple variables of the same structure types.
//    (b) We can initialize the variables as follows:
//        1.  struct {
//              double real;
//              double imaginary;
//            } c1 = { 0.0, 1.0 },
//              c2 = { .real = 1.0, .imaginary = 0.0 },
//              c3;
//        2.  struct complex_number {
//              double real;
//              double imaginary;
//            } c1 = { .imaginary = 1.0, .real = 0.0 },
//              c2 = { .real = 1.0, .imaginary = 0.0 },
//              c3;
//        3.  typedef struct {
//              double real;
//              double imaginary;
//            } complex_number;
//    
//            complex_number c1 = { 0.0, 1.0 }, c2 = { .imaginary = 0.0, .real = 1.0 }, c3;
//    (c) We can only use a single statment to copy the members from one structure to another structure for the structures declared and defined above. There is a scenario when we need to use two statements to copy the members of a structure. Consider the program:
//        struct {
//          double real;
//          double imaginary;
//        } c1;
//
//        struct {
//          double real;
//          double imaginary;
//        } c2;
//
//        c1 = { 1.0, 0.0 };
//        c2.real = c1.real;
//        c2.imaginary = c1.imaginary;
//
//      In this case, we can't simply copy the members of structure c1 into the structure c2. 
//    
//    (d) The statement required is:
//        c3.real = c1.real + c2.real;
//        c3.imaginary = c1.imaginary + c2.imaginary;

#include <stdio.h>

#define CASE_ONE_VAR(n)   c_one_var   ##  n
#define CASE_TWO_VAR(n)   c_two_var   ##  n
#define CASE_THREE_VAR(n) c_three_var ##  n

int main (void) {

  struct {
    double real;
    double imaginary;
  } CASE_ONE_VAR(1) = { 0.0, 1.0 }, 
    CASE_ONE_VAR(2) = { .real = 1.0, .imaginary = 0.0 },
    CASE_ONE_VAR(3);

  struct complex_number {
    double real;
    double imaginary;
  } CASE_TWO_VAR(1) = { .imaginary = 1.0, .real = 0.0 }, 
    CASE_TWO_VAR(2) = { .real = 1.0, .imaginary = 0.0 }, 
    CASE_TWO_VAR(3);

  typedef struct {
    double real;
    double imaginary;
  } complex_number_1;

  complex_number_1  CASE_THREE_VAR(1) = { 1.0, 0.0 }, 
                    CASE_THREE_VAR(2) = CASE_THREE_VAR(1), 
                    CASE_THREE_VAR(3);

  CASE_ONE_VAR(3).real      = CASE_ONE_VAR(1).real      + CASE_ONE_VAR(2).real;
  CASE_ONE_VAR(3).imaginary = CASE_ONE_VAR(1).imaginary + CASE_ONE_VAR(2).imaginary;

  printf("Test Case 1: \n");
  printf("CASE_ONE_VAR(1) has the value (real and imaginary): %g and %g respectively.\n", CASE_ONE_VAR(1).real, CASE_ONE_VAR(1).imaginary);
  printf("CASE_ONE_VAR(2) has the value (real and imaginary): %g and %g respectively.\n", CASE_ONE_VAR(2).real, CASE_ONE_VAR(2).imaginary);
  printf("CASE_ONE_VAR(3) has the value (real and imaginary): %g and %g respectively.\n", CASE_ONE_VAR(3).real, CASE_ONE_VAR(3).imaginary); 
  
  CASE_TWO_VAR(3).real      = CASE_TWO_VAR(1).real      + CASE_TWO_VAR(2).real;
  CASE_TWO_VAR(3).imaginary = CASE_TWO_VAR(1).imaginary + CASE_TWO_VAR(2).imaginary;

  printf("Test Case 2: \n");
  printf("CASE_TWO_VAR(1) has the value (real and imaginary): %g and %g respectively.\n", CASE_TWO_VAR(1).real, CASE_TWO_VAR(1).imaginary);
  printf("CASE_TWO_VAR(2) has the value (real and imaginary): %g and %g respectively.\n", CASE_TWO_VAR(2).real, CASE_TWO_VAR(2).imaginary);
  printf("CASE_TWO_VAR(3) has the value (real and imaginary): %g and %g respectively.\n", CASE_TWO_VAR(3).real, CASE_TWO_VAR(3).imaginary);

  CASE_THREE_VAR(3).real      = CASE_THREE_VAR(1).real      + CASE_THREE_VAR(2).real;
  CASE_THREE_VAR(3).imaginary = CASE_THREE_VAR(1).imaginary + CASE_THREE_VAR(2).imaginary;

  printf("Test Case 3: \n");
  printf("CASE_THREE_VAR(1) has the value (real and imaginary): %g and %g respectively.\n", CASE_THREE_VAR(1).real, CASE_THREE_VAR(1).imaginary);
  printf("CASE_THREE_VAR(2) has the value (real and imaginary): %g and %g respectively.\n", CASE_THREE_VAR(2).real, CASE_THREE_VAR(2).imaginary);
  printf("CASE_THREE_VAR(3) has the value (real and imaginary): %g and %g respectively.\n", CASE_THREE_VAR(3).real, CASE_THREE_VAR(3).imaginary);
  
  return 0;
}
