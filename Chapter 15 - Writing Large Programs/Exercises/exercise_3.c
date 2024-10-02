// Q. We saw that writing #include <file> instead of #include "file" may not work if file is one that we've written. Would there be any problem with writing #include "file" instead of #include <file> if file is a system header? 

// As described in #7 of Chapter's Notes, it is possible to write system header inside double quotation instead of angle brackets. When using the double quotes, the compiler first searches for the current directory, and, if it fails to locate one, it will find the header in theimplementation-defined location where the system header resides.
// NOTE: Be careful when naming custom header. If there exists a user-implemented header called, say, stdio.h, then the compiler will use the header that is user-defined instead of the system header if we use the double quotes. (Although I am not certain if the compiler can allow naming custom header with names that align with system header.)

#include "stdio.h"

int main (void) {

  printf("Hello, World!");
  printf("\nThis program included the system header using double quotation instead of angle brackets.\n");

  return 0;
}
