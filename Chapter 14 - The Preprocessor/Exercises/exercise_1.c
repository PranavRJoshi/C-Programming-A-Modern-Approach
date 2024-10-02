// Q. Wrtie parameterized macros that compute the following values:
//    a. The cube of x
//    b. The remainder when n is divied by 4
//    c. 1 if the product of x and y is less than 100, 0 otherwise
// Do your macros always work? If not, describe what arguments would make them fail.

// result:
// 1. The Macro for finding the remainder when n is divided by 4 will not work (Invalid operands to binary expression 'int' and 'float'), when passing a float type argument (double too)
// 2. The Macros won't work when passed an argument of type char * (string). This should have been obvious, but did so for the purpose of testing.
// Apart from these errors, I think that the macros are well defined as taught in the chapter (the importance of extra parentheses)

#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))

#define REM_WHEN_DIV_BY_FOUR(x)         \
((x) % 4)

#define CHECK_LESS_THAN_100(x, y)       \
(((x) * (y)) < 100 ? 1 : 0)

int main (void) {

  int i, j;
  int i_result;

  i = 10, j = 20;

  printf("The current value of i and j are: %d and %d\n", i, j);
  i_result = CUBE(i);
  printf("[INT TEST CUBE] The result obtained from calling the CUBE(i) macro is: %d\n", i_result);
  i_result = CUBE(i + 10);
  printf("[INT TEST CUBE] The result obtained from calling the CUBE(i + 10) macro is: %d\n", i_result);
  i_result = REM_WHEN_DIV_BY_FOUR(j);
  printf("[INT TEST REM_WHEN_DIV_BY_FOUR] The result obtained from calling REM_WHEN_DIV_BY_FOUR(j) is: %d\n", i_result);
  i_result = REM_WHEN_DIV_BY_FOUR(j / 100);
  printf("[INT TEST REM_WHEN_DIV_BY_FOUR] The result obtained from calling REM_WHEN_DIV_BY_FOUR(j / 100) is: %d\n", i_result);
  i_result = CHECK_LESS_THAN_100(i, j);
  printf("[INT TEST CHECK_LESS_THAN_100] The result obtainted from calling CHECK_LESS_THAN_100(i, j) is: %d\n", i_result);
  i_result = CHECK_LESS_THAN_100(i + 100, j - 100);
  printf("[INT TEST CHECK_LESS_THAN_100] The result obtainted from calling CHECK_LESS_THAN_100(i + 100, j - 100) is: %d\n", i_result);

  // printf("\n\n");

  // float x, y;
  // float f_result;
  //
  // x = 12.5;
  // y = 62.7;
  //
  // printf("The current value of i and j are: %.2f and %.2f\n", x, y);
  // f_result = CUBE(x);
  // printf("[FLOAT TEST CUBE] The result obtained from calling the CUBE(i) macro is: %.2f\n", f_result);
  // f_result = CUBE(x + 15);
  // printf("[FLOAT TEST CUBE] The result obtained from calling the CUBE(i + 10) macro is: %.2f\n", f_result);
  // f_result = REM_WHEN_DIV_BY_FOUR(y);
  // printf("[FLOAT TEST REM_WHEN_DIV_BY_FOUR] The result obtained from calling REM_WHEN_DIV_BY_FOUR(j) is: %.2f\n", f_result);
  // f_result = REM_WHEN_DIV_BY_FOUR(y / 43);
  // printf("[FLOAT TEST REM_WHEN_DIV_BY_FOUR] The result obtained from calling REM_WHEN_DIV_BY_FOUR(j / 100) is: %.2f\n", f_result);
  // f_result = CHECK_LESS_THAN_100(x, y);
  // printf("[FLOAT TEST CHECK_LESS_THAN_100] The result obtainted from calling CHECK_LESS_THAN_100(i, j) is: %.2f\n", f_result);
  // f_result = CHECK_LESS_THAN_100(x + 34, y - 75);
  // printf("[FLOAT TEST CHECK_LESS_THAN_100] The result obtainted from calling CHECK_LESS_THAN_100(i + 100, j - 100) is: %.2f\n", f_result);
  //
  // double lx, ly;
  // double d_result;
  //
  // unsigned long uli, ulj;
  // unsigned long ul_result;
  //
  // char ch1, ch2;
  // char c_result;

  
  return 0;
}

