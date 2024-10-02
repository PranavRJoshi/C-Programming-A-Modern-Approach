// Q. Assume that debug.h is a header file with the following contents:
//    #ifdef DEBUG
//      #define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)
//    #else 
//      #define PRINT_DEBUG(n) 
//    #endif
//
// Let testdebug.c (I will use exercise_4.c instead) be the following source file:
//    #include <stdio.h>
//
//    #define DEBUG 
//    #include "debug.h" 
//
//    int main (void) {
//      int i = 1, j = 2, k = 3;
//
//      #ifdef DEBUG 
//        printf("Output if DEBUG is defined:\n");
//      #else 
//        printf("Output if DEBUG is not defined:\n");
//      #endif
//
//      PRINT_DEBUG(i);
//      PRINT_DEBUG(j);
//      PRINT_DEBUG(k);
//      PRINT_DEBUG(i + j);
//      PRINT_DEBUG(2 * i + j - k);
//
//      return 0;
//    }
//
//    a. What is the output when the program is executed?
//    b. What is the output if the #define directive is removed from testdebug.c (exercise_4.c)?
//    c. Explain why the output is different in parts (a) and (b) 
//    d. Is it necessary for the DEBUG macro to be defined before debug.h is included in order for PRINT_DEBUG to have the desired effect? Justify your answer.
//
// Answer (my assumptions)
//    a. The output will probably be: 
//        Output if DEBUG is defined:
//        Value of i: 1
//        Value of j: 2
//        Value of k: 3 
//        Value of i + j: 3 
//        Value of 2 * i + j - k: 1
//    b. The output will probably be:
//        Output if DEBUG is defined:
//    c. The output is different in (a) and (b), since DEBUG is defined in the source file, which make the condition true for #ifdef DEBUG in the debug.h header file. This results in a macro that has a replacement list defined too, which makes it possible to print out the results. But in the other case, as DEBUG is not defined, the #else directive is applied in debug.h header file, which defines the macro PRINT_DEBUG macro, but the macro is empty, so no printing will take place when calling PRINT_DEBUG. 
//    d. As we studied, when we use the include directive, the contents of the file that is being included will be pasted in place of the include line. Since this is what happens, it is essential to define the DEBUG macro before we include the debug.h header. If we fail to do so, we get the result that is similar to the one in (b), which is not the desired result. 
//
// Actual result:
//  As expected.

#include <stdio.h>

#define DEBUG 
#include "debug.h" 

int main (void) {
  int i = 1, j = 2, k = 3;

#ifdef DEBUG 
   printf("Output if DEBUG is defined:\n");
#else 
   printf("Output if DEBUG is not defined:\n");
#endif

  PRINT_DEBUG(i);
  PRINT_DEBUG(j);
  PRINT_DEBUG(k);
  PRINT_DEBUG(i + j);
  PRINT_DEBUG(2 * i + j - k);

  return 0;
}

