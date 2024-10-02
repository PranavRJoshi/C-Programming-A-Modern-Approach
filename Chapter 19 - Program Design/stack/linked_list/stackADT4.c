#include <stdio.h>
#include <stdlib.h>
#include "stackADT4.h"

#define STACK_SIZE 100

#define MALLOC_IS_NULL(addr)                                                                                                            \
if (!(addr)) {                                                                                                                          \
  fprintf(stderr, "Memory allocation failed when calling function %s in file %s and on line %d\n", __func__, __FILE__, __LINE__);       \
  exit(EXIT_FAILURE);                                                                                                                   \
}

struct node {
  Item content;
  struct node *next;
};

struct stack_type {
  struct node *top;
};

static void terminate (const char *message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create (void) {
  Stack node = malloc(sizeof(struct stack_type));
  MALLOC_IS_NULL(node);
  node->top = NULL;
  return node;
}

void make_empty(Stack s) {
  while (!is_empty(s)) {
    pop(s);
  }
  /*
   * The above function creates overhead by calling the is_empty function and the pop function.
   * We don't have any requirements to use the pop function and we don't need the content as well.
   * So, the code below can be used as an alternative as well.
  */
  // while (s->top) {
  //   struct node *old_item = s->top;
  //   s->top = s->top->next;
  //   free(old_item);
  //   old_item = NULL;
  // }
  s->top = NULL;
}

bool is_empty(Stack s) {
  return s->top == NULL;
}

bool is_full(Stack s) {
  return false;
}

void push(Stack s, Item i) {
  struct node *add_item = malloc(sizeof(struct node));
  MALLOC_IS_NULL(add_item);
  add_item->content = i;
  add_item->next = s->top;
  s->top = add_item;
}

Item pop(Stack s) {
  if (is_empty(s)) {
    terminate("Error in pop, stack is empty");
  }
  struct node *old_node = s->top;
  Item value = old_node->content;
  s->top = old_node->next;
  free(old_node);
  old_node = NULL;
  return value;
}

void destroy (Stack s) {
  make_empty(s);
  /* Alternative to freeing up the contents of stack without calling the make_empty, creating overhead. */
  // while (s->top) {
  //   struct node *old_node = s->top;
  //   s->top = s->top->next;
  //   free(old_node);
  //   old_node = NULL;
  // }
  free(s);
  s = NULL;
}

/* Exercise 6(c) */
Item peek (Stack s) {
  if (is_empty(s)) {
    terminate("Error in peek, stack is empty");
  }
  return s->top->content;
}

