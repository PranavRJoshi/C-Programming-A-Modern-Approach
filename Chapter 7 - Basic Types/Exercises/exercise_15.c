// Q. Use typedef to create types named Int8, Int16, and Int32. Define the types so that they represent 8-bit, 16-bit, and 32-bit integers on your machine.

#include <stdio.h>
#include <stdint.h>

// we can approach this problem in two ways
// first, we can use the stdint header that provides types like int8_t, int16_t, and int32_t.
// second, we can use char to represent 8 bit, short int to represent 16 bit, and int to represent 32 bit.
// Since, the second one is unreliable on other machine, we'll use the first one.

int main (void) {

  typedef int8_t Int8;
  typedef int16_t Int16;
  typedef int32_t Int32;

  printf("Size of Int8 is %zu\n", sizeof(Int8));
  printf("Size of Int16 is %zu\n", sizeof(Int16));
  printf("Size of Int32 is %zu\n", sizeof(Int32));

  return 0;
}

