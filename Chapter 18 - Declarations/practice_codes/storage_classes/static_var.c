#include "static_var.h"
#include <stdio.h>

int s_i = 0;
/* NOTE:  need to specify the type of the variable defined with extern--count in this case--in place 
 *        where the definition of count is defined. 
*/
int count = 0;

/* ERROR: Illegal storage class on file-scoped variable */
// register long long int lld_j = 0;

void s_incrementor (void) {
  printf("\n\n***Contents from the %s function***\n\n", __func__);
  count++;
  s_i++;
  printf("The current value of s_i from the function %s (void) is: %d\n", __func__, s_i);
  printf("\n\n***End of Contents from the %s function***\n\n", __func__);
}

void total_func_count (void) {
  printf("\n\n***Contents from the %s function***\n\n", __func__);
  count++;
  printf("The total number of function calls is: %d\n", count);
  printf("\n\n***End of Contents from the %s function***\n\n", __func__);
}

void r_checker (void) {
  printf("\n\n***Contents from the %s function***\n\n", __func__);
  register long long int lld_j = 10;

  /* Cannot access the address of a variable with storage class register. */

  // printf("The content of the variable is: %lld and the address of it is: %p\n", lld_j, &lld_j);
  
  printf("The content of the variable lld_j is: %lld\n", lld_j);
  printf("\n\n***End of Contents from the %s function***\n\n", __func__);
}

static void s_func (void) {
  printf("\n\n***Contents from the %s function***\n\n", __func__);
  printf("Called the function %s\n", __func__);
  printf("\n\n***End of Contents from the %s function***\n\n", __func__);
}

void e_checker (void) {
  printf("\n\n***Contents from the %s function***\n\n", __func__);
  printf("The value of the external variable l_count is: %ld\n", l_count);

  printf("The address of the function s_func is: %p\n", (void *) &s_func);

  s_func();
  printf("\n\n***End of Contents from the %s function***\n\n", __func__);
}

void *get_static_function_address (void) {
  void *s_func_address = (void *) &s_func;

  return s_func_address;
}
