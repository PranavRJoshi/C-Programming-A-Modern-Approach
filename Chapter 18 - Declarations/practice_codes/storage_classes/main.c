#include "static_var.h"
#include "extern_var.h"
#include <stdio.h>

/* 
 * l_count is an external variable which, when defined inside the main function
 * throws an error when calling e_checker function. The error suggests that the 
 * variable (l_count) accessed in the e_checker function is an undefined symbol 
 * although the variable is defined inside the scope of main function.
*/
long int l_count = 10;

extern int s_int;

int main (void) {

  // long int l_count = 100;
  
  printf("\n---Contents from the %s function---\n", __func__);

  printf("Hello, World!\n");

  printf("Total function calls from external function call is: %d\n", count); // count is an external variable declared in static_var.h

  s_incrementor();

  printf("Total function calls from external function call is: %d\n", count);

  total_func_count();

  r_checker();
  
  e_checker();

  printf("The value of the variable l_count is: %ld\n", l_count);

  /* The code below shows how function pointers can be manipulated. get_static_function_address is a function that takes
   * no argument and returns the pointer to the function that has been declared and defined static.
   *
   * call_function is a variable of type void which is a pointer to a function whose return type is void and takes no 
   * argument (void). 
   *
   * When call_function is called, it executes the function even though the function s_func is declared and defined as static,*/
  void *static_function_address = get_static_function_address();
  void (*call_function)(void) = (void (*)(void)) static_function_address;

  call_function();

  printf("The address of the static function s_func is: %p\n", static_function_address);

  initialize_se_int(100);

  display_se_int();

  call_func();

  printf("\n---End of Contents from the %s function---\n", __func__);

  return 0;
}

