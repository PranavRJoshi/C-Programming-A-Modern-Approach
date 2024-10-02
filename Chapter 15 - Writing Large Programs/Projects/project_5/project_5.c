// Q. Modify Programming Project 6 from Chapter 10 so that it has separate stack.h and stack.c files, as described in Section 15.2.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "stack.h"

int main (void) {
  
  char ch;
  int digit = 0;
  int first_item = 0;
  int second_item = 0;
  int result = 0;

  for (;;) {
    make_empty();
    printf("Enter an RPN Expression: ");
    scanf(" %c", &ch);
    while (ch != '=') {
      if (ch >= '0' && ch <= '9') {
        digit = ch - '0';
        push(digit);
      } else {
        switch (ch) {
          case '+':
            second_item = pop();
            first_item = pop();
            result = first_item + second_item;
            push(result);
            break;
          case '-':
            second_item = pop();
            first_item = pop();
            result = first_item - second_item;
            push(result);
            break;
          case '*':
            second_item = pop();
            first_item = pop();
            result = first_item * second_item;
            push(result);
            break;
          case '/':
            second_item = pop();
            first_item = pop();
            result = first_item / second_item;
            push(result);
            break;
          default:
            exit(EXIT_SUCCESS);
        }
      }
      scanf(" %c", &ch);
    }
    result = pop();
    if (!is_empty()) {
      printf("[ERROR] Operands left in the stack. Aborted.\n");
    } else {
      printf("Value of expression: %d\n", result);
    }
  }
  return 0;
}

