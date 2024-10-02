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
  char *content;
  struct node *next;
};

struct stack_type_ll {
  struct node *top;
};

static void terminate (const char *message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

Stack_ll create_ll (void) {
  Stack_ll node = malloc(sizeof(struct stack_type_ll));
  MALLOC_IS_NULL(node);
  node->top = NULL;
  return node;
}

void make_empty_ll (Stack_ll s) {
  while (!is_empty_ll(s)) {
    pop_ll(s);
  }
  s->top = NULL;
}

bool is_empty_ll (Stack_ll s) {
  return s->top == NULL;
}

bool is_full_ll (Stack_ll s) {
  return false;
}

void push_ll (Stack_ll s, void *i) {
  struct node *add_item = malloc(sizeof(struct node));
  MALLOC_IS_NULL(add_item);
  add_item->content = i;
  add_item->next = s->top;
  s->top = add_item;
}

void *pop_ll (Stack_ll s) {
  if (is_empty_ll(s)) {
    terminate("Error in pop, stack is empty");
  }
  struct node *old_node = s->top;
  char *value = old_node->content;
  s->top = old_node->next;
  free(old_node);
  old_node = NULL;
  return value;
}

void destroy_ll (Stack_ll s) {
  make_empty_ll(s);
  free(s);
  s = NULL;
}

