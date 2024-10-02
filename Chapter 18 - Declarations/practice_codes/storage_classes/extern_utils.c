#include "extern_utils.h"
#include <stdio.h>

/* find_largest has an inline definition in extern_utils.h 
 * Any file that calls the find_largest function can either be 
 * expanded inline in that file, or it will call the external 
 * definition (defined here) to call the funciton normally. 
 *
 * This is done to conserve the consistency of the function.
*/
extern int find_largest (int x[], int n);

int convert_double (double num) {
  return ((int) num);
}

float convert_long (long num) {
  return ((float) num);
}

int (*f(float (*pf)(long), char *test))(double) {

  printf("\n\n*** Calling from %s function ***\n\n", __func__);

  float f_test = pf(5);

  printf("The result of calling convert_long with 5 as argument is: %f\n", f_test);
  printf("The provided string is: %s\n", test);

  printf("\n\n*** End of Calling from %s function ***\n\n", __func__);

  return convert_double;
}

