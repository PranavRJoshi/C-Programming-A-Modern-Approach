// The programs compared to the books are swaped in context to C's idiom.

#include <stdio.h>

int main (void) {

  int length = 0;
  char ch;

  printf("Enter a message: ");
  ch = getchar();

  while (ch != '\n') {
    length++;
    ch = getchar();
  }

  printf("Your message was %d character(s) long.", length);

  return 0;  
}

