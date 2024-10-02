// Q. Suppose that the macro M has been defined as follows:
//    #define M 10
// Which of the following test will fail? 
//    a. #if M
//    b. #ifdef M
//    c. #ifndef M
//    d. #if defined(M)
//    e. #if !defined(M)

// Since M is a macro that is defined and the replacement list contains 10, whenever M is appeared in the file, M is replaced by 10
// So, the following ones will be passed and failed:
//    a. Passed, as M is not only defined, but also has a nonzero value
//    b. Passed, as M is defined (it does not matter if M has a zero or nonzero value)
//    c. Failed, as M is defined, but #ifndef will pass only if M is not defined
//    d. Passed, this is the same as using #ifdef--which is similar to question b--and it passes the test
//    e. Failed, as !defined(M) will pass only if M is not defined. 

#include <stdio.h>

#define M 10

#if M 
#define IF_PASSED 1
#endif

#ifdef M 
#define IFDEF_PASSED 1
#endif

#ifndef M
#define IFNDEF_PASSED 1
#endif

#if defined(M)
#define IF_DEFINED_PASSED 1
#endif

#if !defined(M)
#define IF_NOT_DEFINED_PASSED 1
#endif

int main (void) {

  #if IF_PASSED
    printf("#if M has passed.\n");
  #else 
    printf("#if M has failed.\n");
  #endif

  #if IFDEF_PASSED
    printf("#ifdef M has passed.\n");
  #else 
    printf("#ifdef M has failed.\n");
  #endif

  #if IFNDEF_PASSED
    printf("#ifndef M has passed.\n");
  #else 
    printf("#ifndef M has failed.\n");
  #endif

  #if IF_DEFINED_PASSED
    printf("#if defined(M) has passed.\n");
  #else
    printf("#if defined(M) has failed.\n");
  #endif

  #if IF_NOT_DEFINED_PASSED
    printf("#if !defined(M) has passed.\n");
  #else
    printf("#if !defined(M) has failed.\n");
  #endif

  return 0;
}

