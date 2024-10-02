#include <stdio.h>
#include <stdlib.h>
#include "stackADT3.h"

#define MALLOC_IS_NULL(addr)                                                                                                            \
if (!(addr)) {                                                                                                                          \
  fprintf(stderr, "Memory allocation failed when calling function %s in file %s and on line %d\n", __func__, __FILE__, __LINE__);       \
  exit(EXIT_FAILURE);                                                                                                                   \
}

#define FREE_AND_NULL(addr)               \
free((addr));                             \
addr = NULL

struct stack_type {
  Item *contents;
  int top;
  int size;
};

static void terminate (const char *message) {
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create (int size) {
  struct stack_type *node = malloc(sizeof(struct stack_type));
  MALLOC_IS_NULL(node);
  node->contents = malloc(sizeof(Item) * size);
  if (node->contents == NULL) {
    node = NULL;
    terminate("Error in create: stack could not be created.");
  }
  node->top = 0;
  node->size = size;
  return node;
}

void make_empty(Stack s) {
  s->top = 0;
}

bool is_empty(Stack s) {
  return s->top == 0;
}

bool is_full(Stack s) {
  return s->top == s->size;
}

void push(Stack s, Item i) {
  if (is_full(s)) {
    printf("[LOG] Stack is full, Doubling the storage.\n");
    /* Creating a new Stack type and allocating double the size of the previous Stack. */
    // struct stack_type *temp;
    // temp = malloc(sizeof(struct stack_type));
    // MALLOC_IS_NULL(temp);
    // temp->contents = malloc(sizeof(Item) * s->size * 2);
    // MALLOC_IS_NULL(temp->contents);
    // temp->size = s->size * 2;
    /* Copying the data from the older stack to the new one. */
    // for (int i = 0; i < s->size; i++) {
    //   
    // }
    Item *swap = s->contents;
    /* reallocating the contents member with double the size */
    s->contents = realloc(s->contents, s->size * 2);
    MALLOC_IS_NULL(s->contents);
    /* Copying the previously stored value */
    for (int i = 0; i < s->size; i++) {
      s->contents[i] = swap[i];
    }
    /* Updating the new size of the Stack variable */
    s->size = s->size * 2;
  }
  s->contents[s->top++] = i; 
  // (s->contents)[(s->top)++] = i;
}

Item pop(Stack s) {
  if (is_empty(s)) {
    terminate("Error in pop, stack is empty");
  }
  return s->contents[--s->top];
  // return (s->contents)[--(s->top)];
}

void destroy (Stack s) {
  FREE_AND_NULL(s->contents);
  // free(s->contents);
  // s->contents = NULL;
  FREE_AND_NULL(s);
  // free(s);
  // s = NULL;
}

/* Exercise 6(b) */
Item peek (Stack s) {
  if (is_empty(s)) {
    terminate("Error in peek, stack is empty");
  }
  int stack_index = s->top - 1;
  return s->contents[stack_index];
}

