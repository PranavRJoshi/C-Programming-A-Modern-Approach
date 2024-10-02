#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

#define MALLOC_IS_NULL(addr)                                                                                                            \
if (!(addr)) {                                                                                                                          \
  fprintf(stderr, "Memory allocation failed when calling function %s in file %s and on line %d\n", __func__, __FILE__, __LINE__);       \
  exit(EXIT_FAILURE);                                                                                                                   \
}

struct stack_type {
  int contents[STACK_SIZE];
  int top;
};

static void terminate (const char *message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create (void) {
  struct stack_type *node = malloc(sizeof(struct stack_type));
  MALLOC_IS_NULL(node);
  node->top = 0;
  return node;
}

void make_empty(Stack s) {
  s->top = 0;
}

bool is_empty(Stack s) {
  return s->top == 0;
}

bool is_full(Stack s) {
  return s->top == STACK_SIZE;
}

void push(Stack s, int i) {
  if (is_full(s)) {
    terminate("Error in push, stack is full.");
  }
  s->contents[s->top++] = i; 
  // (s->contents)[(s->top)++] = i;
}

int pop(Stack s) {
  if (is_empty(s)) {
    terminate("Error in pop, stack is empty");
  }
  return s->contents[--s->top];
  // return (s->contents)[--(s->top)];
}

void destroy (Stack s) {
  free(s);
  s = NULL;
}

/* Exercise 6(a) */
int peek (Stack s) {
  if (is_empty(s)) {
    terminate("Error in peek, stack is empty");
  }
  int stack_index = s->top - 1;
  return s->contents[stack_index];
}

