#include <stdio.h>

int f (int i) {
  static int j = 0;
  return i * j++;
}

int main (void) {
  for (int i = 0; i < 5; i++) {
    printf("Call %d to the function f, and it returned %d\n", i, f(10));
  }
}
