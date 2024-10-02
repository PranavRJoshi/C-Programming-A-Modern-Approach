#include <stdio.h>

void print_error (const char *message) {
  static int n = 1;
  printf("Error %d: %s\n", n++, message);
}

int main (void) {
  print_error("[ERROR] Divide by Zero.");
  print_error("[ERROR] Memory Allocation Failed.");
  print_error("[ERROR] Segmentation Fault.");
}
