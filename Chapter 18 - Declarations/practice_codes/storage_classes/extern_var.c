#include <stdio.h>
#include "extern_var.h"
#include "extern_utils.h"
#include "pointer_fiesta.h"

static int static_extern_x;

void initialize_se_int (int value) {
  extern int static_extern_x;

  static_extern_x = value;
}

void display_se_int (void) {
  printf("The value of static_extern_int is %d and the address of the variable is %p\n", static_extern_x, (void *) &static_extern_x);

  /*
   * (int []){2, 1} is a way to initialize a compound literal
   * an array of element [2, 1] is made
   * [1 < 2] is a way to find the index of the element with a condition
   * 1 < 2, which is true, so it returns 1, and hence x has the value 1
  */
  int x = (int []){2, 1}[1 < 2];
  printf("The variable x contains %d\n", x);
  printf("The largest number is: %d\n", find_largest((int []){1, 2, 3, 4, 5}, 5));
}

void call_func (void) {

  initialize_unity_matrix(5);

  int (*weird_func)(double) = f(convert_long, "test");

  printf("The pointer to a function that takes a double as an argument and returns an int is: %p\n", (void *) weird_func);

  initialize_space(2, 4, 6);

  initialize_quartic(2, 3, 4, 5);

  initialize_quintic((int []){5, 4, 3, 2, 1});
}
