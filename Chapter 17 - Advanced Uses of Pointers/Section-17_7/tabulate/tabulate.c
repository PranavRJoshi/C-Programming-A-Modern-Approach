// The following program prints tables showing the values of cos, sin, and tan functions (all three belong to <math.h>). The program is built around a function named tabulate that, when passed a function pointer f, prints a table showing the values of f.

/* Tabulates values of trigonometric functions */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void tabulate(double (*f)(double), double first, double last, double incr);

void clear_input_stream (void);

int main (void) {

  double final, increment, initial;
  int scanf_return_count = 0;

  for (;;) {
    printf("Enter initial value: ");
    if ((scanf_return_count = scanf("%lf", &initial)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  for (;;) {
    printf("Enter final value: ");
    if ((scanf_return_count = scanf("%lf", &final)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  for (;;) {
    printf("Enter increment: ");
    if ((scanf_return_count = scanf("%lf", &increment)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  printf("\n    x         cos(x)"                       \
         "\n  -----     ----------\n");
  tabulate(cos, initial, final, increment);

  printf("\n    x         sin(x)"                       \
         "\n  -----     ----------\n");
  tabulate(sin, initial, final, increment);
  
  printf("\n    x         tan(x)"                       \
         "\n  -----     ----------\n");
  tabulate(tan, initial, final, increment);

  return 0;
}

// tabulate uses the ceil function, which also in <math.h>. When given an argument x of double type, 
// ceil returns the smallest integer that's greater than or equal to x.

void tabulate (double (*f)(double), double first, double last, double incr) {
  double x;
  int i, num_intervals;

  num_intervals = ceil((last - first) / incr);
  for (i = 0; i <= num_intervals; i++) {
    x = first + i * incr;
    printf("%10.5f %10.5f\n", x, (*f)(x));
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}
