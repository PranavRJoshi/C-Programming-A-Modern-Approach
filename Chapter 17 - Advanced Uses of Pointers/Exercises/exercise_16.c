// Q. Write the following function. The call sum(g, i, j) should return g(i) + ... + g(j).
//    int sum (int (*f)(int), int start, int end);

#include <stdio.h>

int square (int num);

int sum (int (*f)(int), int start, int end);

void clear_input_stream (void);

int main (void) {

  int lower, upper;
  int scanf_return_count = 0;

  int sum_of_squares = 0;

  for (;;) {
    printf("Enter the lower range and upper range (format: lower, upper): ");
    if ((scanf_return_count = scanf("%d ,%d", &lower, &upper)) != 2) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    if (lower > upper) {
      fprintf(stderr, "[WARN] The lower range should not be greater than upper range. Try Again.\n");
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }
  
  sum_of_squares = sum(square, lower, upper);
  // sum_of_squares = sum(&square, lower, upper);

  printf("[LOG] The sum of the square is: %d\n", sum_of_squares);

  return 0;
}

int square (int n) {
  return n * n;
}

int sum (int (*f)(int), int s, int e) {
  int sum = 0;
  while (s <= e) {
    // sum += f(s);
    sum += (*f)(s);
    s++;
  }

  return sum;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

