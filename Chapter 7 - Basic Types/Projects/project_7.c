// Q. Modify Programming Project 6 from Chapter 3 so that the user may add, subtract, multiply, or divide two fractions (by entering either +, -, *, or / between the fractions).

#include <stdio.h>

int main (void) {

  int num_1, num_2;
  int denom_1, denom_2;
  char ch;

  printf("Enter two fractions separated by +, -, *, or /: ");
  scanf("%d/%d %c %d/%d", &num_1, &denom_1, &ch, &num_2, &denom_2);

  // This program can be polished by having a result numerator and denominator. And there can be checking conditions to see if the numerator and denominator are same, in that case, simply 1 can be displayed instead of, let's say, 4/4. But the functionality of the program is as required.
  switch (ch) {
    case '+':
      printf("The sum is: %d/%d\n", (num_1 * denom_2 + num_2 * denom_1), (denom_1 * denom_2));
      break;
    case '-':
      printf("The difference is: %d/%d\n", (num_1 * denom_2 - num_2 * denom_1), (denom_1 * denom_2));
      break;
    case '*':
      printf("The multiplication is: %d/%d\n", (num_1 * num_2), (denom_1 * denom_2));
      break;
    case '/':
      printf("The division is: %d/%d\n", (num_1 * denom_2), (num_2 * denom_1));
      break;
    default:
      printf("ERROR: Invalid symbol encountered.");
      break;
  }

  return 0;

}

