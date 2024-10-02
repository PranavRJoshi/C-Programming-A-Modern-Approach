// Q. Let GENERIC_MAX be the following macro:
//    #define GENERIC_MAX(type)             \
//    type type##_max (type x, type y) {    \
//      return x > y ? x : y;               \
//    }
// a. Show the preprocessor's expansion of GENERIC_MAX(long).
// b. Explain why GENERIC_MAX doesn't work for basic types such as unsigned long.
// c. Describe a technique that would allow us to use GENERIC_MAX with basic types such unsigned long. Hint: Don't change the definition of GENERIC_MAX.

// a. When GENERIC_MAX(long) is called--with no semicolon at the end--and the following expansion will take place:
//    long long_max (long x, long y) {
//      return x > y ? x : y;
//    }
//
// b. The reason why GENERIC_MAX doesn't work for basic types such as unsigned long, unsigned long long (C99), long double, and pretty much any data type that is made of more than one word, is, if we were to invoke GENERIC_MAX as GENERIC_MAX(unsigned long), the following expansion would happen:
//    unsigned long unsigned long_max (unsigned long x, unsigned long y) {
//      return x > y ? x : y;
//    }
// NOTE: Notice that the function has an incorrect form--there is a spacing between unsigned and long_max--and so it is not understood as intented. The function definition should be of the form:
//    return-type function-name (parameter_1, parameter_2, ...) {
//      function body
//    }
//
// c. To correct this, we can do what we did with boolean data types--introduce another macro that functions as we intend it to. For instance, if we need to use unsigned long as a data type for GENERIC_MAX, we need to do so as the following:
//    #define ulint_t unsinged long
//
//    GENERIC_MAX(ulint_t)

#include <stdio.h>

#define ulint_t unsigned long

#define GENERIC_MAX(type)             \
type type##_max (type x, type y) {    \
return x > y ? x : y;                 \
}

GENERIC_MAX(long)
GENERIC_MAX(ulint_t)

int main (void) {

  ulint_t ul_result = 0ul;
  long l_result = 0l;

  ul_result = ulint_t_max(100ul, 120ul);
  l_result = long_max(420l, 500l);

  printf("Calling GENERIC_MAX with the type of unsigned long is: %lu\n", ul_result);
  printf("Calling GENERIC_MAX with the type of long is: %ld\n", l_result);

  return 0;
}
