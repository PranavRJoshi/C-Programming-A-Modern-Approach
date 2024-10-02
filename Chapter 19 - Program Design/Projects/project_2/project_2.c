// Q. Modify Programming Project 6 from Chapter 10 so that it uses the stack ADT described in Section 19.4. You may use any of the implementataions of the ADT described in that section.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 5

int contents[STACK_SIZE] = {0};

int main (void) {

  Stack s;

  s = create();
  
  char ch;
  int digit = 0;
  int first_item = 0;
  int second_item = 0;
  int result = 0;

  for (;;) {
    printf("Enter an RPN Expression: ");
    scanf(" %c", &ch);
    while (ch != '=') {
      if (ch >= '0' && ch <= '9') {
        digit = ch - '0';
        push(s, digit);
      } else {
        switch (ch) {
          case '+':
            second_item = pop(s);
            first_item = pop(s);
            result = first_item + second_item;
            push(s, result);
            break;
          case '-':
            second_item = pop(s);
            first_item = pop(s);
            result = first_item - second_item;
            push(s, result);
            break;
          case '*':
            second_item = pop(s);
            first_item = pop(s);
            result = first_item * second_item;
            push(s, result);
            break;
          case '/':
            second_item = pop(s);
            first_item = pop(s);
            result = first_item / second_item;
            push(s, result);
            break;
          default:
            exit(EXIT_SUCCESS);
        }
      }
      scanf(" %c", &ch);
    }
    result = pop(s);
    if (!is_empty(s)) {
      printf("[ERROR] Operands left in the stack. Clearing Stack.\n");
      make_empty(s);
    } else {
      printf("Value of expression: %d\n", result);
    }
  }
  
  destroy(s);

  return 0;
}

