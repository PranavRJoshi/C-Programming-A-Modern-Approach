// Q. Give the decimal value of each of the following integer constants:
//    a. 077
//    b. 0x77
//    c. 0XABC
// Expectation:
//    a. 077 (is in octal) -> 63
//    b. 0x77 (is in hex) -> 119
//    c. 0XABC (is in hex) -> 2748
// Actual: as expected

#include <stdio.h>

int main (void) {

  int num_1 = 077;    // need to precede the number with 0 to tell the compiler it's a octal number
  int num_2 = 0x77;   // need to precede the number with 0x to tell the compiler it's a hex number
  int num_3 = 0XABC;

  printf("077 in decimal is: %d\n", num_1);
  printf("0x77 in decimal is: %d\n", num_2);
  printf("0XABC in decimal is: %d\n", num_3);

  return 0;
}

