// Q. Let DOUBLE be the following macro:
//    #define DOUBLE(x) 2 * x
//    
//    a. What is the value of DOUBLE(1 + 2);
//    b. What is the value of 4 / DOUBLE(2);
//    c. Fix the definition of DOUBLE.

// For a,
// When the preprocessor encounters DOUBLE(1 + 2) invoked in the source file, it expands as the following
// 2 * 1 + 2 ---> 2 + 2 ---> 4
// The correct answer should have been
// 2 * (1 + 2) ---> 2 * 3 ---> 6
//
// For b,
// When the preprocessor encounters 4 / DOUBLE(2) invoked in the source file, the macro is expanded as follows (along with other operands)
// 4 / 2 * 2 ---> 2 * 2 ---> 4
// The correct answer should have been
// 4 / (2 * 2) ---> 4 / 4 ---> 1
//
// For c,
// Whenever we encounter the macro parameter in the replacement list, it is advised to use:
//    1. parentheses around the macro's parameter--in the replacement list--whenever it is used as an operand
//    2. parentheses around an operation, i.e. when an operator is present.

#include <stdio.h>

#define DOUBLE(x) 2 * x

#define DOUBLE_FIXED(x) (2 * (x))

int main (void) {

  int i = 21;

  int result = DOUBLE(i + 10);

  printf("[DOUBLE TEST] After invoking DOUBLE(i + 10), the result obtained is: %d\n", result);

  result = DOUBLE_FIXED(i + 10);

  printf("[DOUBLE_FIXED TEST] After invoking DOUBLE_FIXED(i + 10), the result obtained is: %d\n", result);

  return 0;
}

