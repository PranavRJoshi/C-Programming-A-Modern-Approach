#include <stdio.h>
#include <string.h>

#define STR_LEN 100


int main (void) {

  char c_arr[STR_LEN + 1];

  strcpy(c_arr, "tire-bouchon");
  strcpy(&c_arr[4], "d-or-wi");
  strcat(c_arr, "red?");

  printf("c_arr holds: %s", c_arr);

  return 0;
}
