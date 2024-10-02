#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 5

int contents[STACK_SIZE] = {0};
int top = 0;

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


