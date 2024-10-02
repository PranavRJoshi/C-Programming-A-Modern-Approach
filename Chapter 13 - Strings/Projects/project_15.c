// Q. Modify Programming Project 6 from Chapter 10 so that it includes the following function:
//    int evaluate_RPN_expression (const char *expression);
// The function returns the value of the RPN expression pointed to by expression.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 120
#define EXPRESSION_SIZE 100

// external/global variable declaration and initialization.
int contents[STACK_SIZE] = {0};
int top = 0;

void make_empty (void);
bool is_empty (void);
bool is_full (void);
void push (int item);
int pop (void);
void stack_overflow (void);
void stack_underflow (void);

int evaluate_RPN_expression (const char *expression);

int main (void) {
  
  char ch;
  char expression[EXPRESSION_SIZE];
  char *expr_ptr = expression;
  int result = 0;

  printf("Enter an expression: ");
  while ((ch = getchar()) != '\n') {
    if (ch >= '0' && ch <= '9') {
      *expr_ptr++ = ch;
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=') {
      *expr_ptr++ = ch;
    }
  }

  *expr_ptr = '\0';

  result = evaluate_RPN_expression(expression);

  printf("The result of the RPN expression is: %d\n", result);

  return 0;
}

int evaluate_RPN_expression (const char *e) {

  int digit = 0;
  int first_item = 0;
  int second_item = 0;
  int result = 0;

  make_empty();

  while (*e != '=') {
    if (*e >= '0' && *e <= '9') {
      digit = *e - '0';
      push(digit);
    } else {
      switch (*e) {
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
    e++;
  }
  result = pop();
  if (!is_empty()) {
    printf("[ERROR] Operands left in the stack. Aborted.\n");
    exit(EXIT_FAILURE);
  } else {
    return result;
  }
}


void make_empty (void) {
  top = 0;
}

bool is_empty (void) {
  return top == 0;
}

bool is_full (void) {
  return top == STACK_SIZE;
}

void push (int i) {
  if (is_full()) {
    stack_overflow();
  } else {
    contents[top++] = i;
  }
}

int pop (void) {
  if (is_empty()) {
    stack_underflow(); 
    return top;
  } else {
    return contents[--top];
  }
}

void stack_overflow (void) {
  printf("[ERROR] Expression is too complex.\n");
  exit(EXIT_FAILURE);
}

void stack_underflow (void) {
  printf("[ERROR] Not enough operands in expression.\n");
  exit(EXIT_FAILURE);
}

