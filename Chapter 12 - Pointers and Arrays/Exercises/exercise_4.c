// Q. Rewrite the make_empty, is_empty, and is_full functions of Section 10.2 to use the pointer variable top_ptr instead of the integer variable top.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

// external/global variable declaration and initialization.
int contents[STACK_SIZE] = {0};
int *top_ptr = &contents[0];

void make_empty (void);
bool is_empty (void);
bool is_full (void);
void push (int item);
int pop (void);
void stack_overflow (void);
void stack_underflow (void);

int main (void) {
  
  int push_item = 0;
  int pop_item = 0;
  int option = 0;

  printf("This Program generates a stack of size %d\n", STACK_SIZE);
  printf("Here are the avaiable commands for the stack:\n");
  printf("1. Push into the stack.\n");
  printf("2. Pop from the stack.\n");
  printf("3. Current stack position.\n");
  printf("4. Clear the stack.\n");
  printf("5. Exit.\n");

  
  for (;;) {
    printf("Enter your option: ");
    scanf("%d", &option);
    
    switch (option) {
      case 1:
        printf("Enter the item to push: ");
        scanf("%d", &push_item);
        push(push_item);
        printf("[SUCCESS] Item pushed into stack.\n");
        break;
      case 2:
        pop_item = pop();
        // when the case that stack is empty, we cannot log any store value.
        if (pop_item == (top_ptr == &contents[0])) {
          break;          
        } else {
          printf("[LOG] The popped item is: %d.\n", pop_item);
          break;
        }
      case 3:
        printf("[LOG] The current top position is: %d.\n", *top_ptr);
        break;
      case 4:
        printf("[LOG] Clearing the stack.\n");
        make_empty();
        printf("[SUCCESS] Cleared the stack.\n");
        break;
      case 5:
        exit(EXIT_SUCCESS);
      default:
        printf("[ERROR] Invalid option entered.\n");
        break;
    }
  }

  return 0;
}

void make_empty (void) {
  top_ptr = &contents[0];
}

bool is_empty (void) {
  return top_ptr == &contents[0];
}

bool is_full (void) {
  return top_ptr == &contents[STACK_SIZE];
}

void push (int i) {
  if (is_full()) {
    stack_overflow();
  } else {
    // first store the item on the top index and then only increment the value of top.
    *top_ptr++ = i;
  }
}

int pop (void) {
  if (is_empty()) {
    stack_underflow(); 
    // non-void function must have a return value in all control path
    // so we instead return the value of top
    return top_ptr == &contents[0];
  } else {
    // top will point to un-assigned position
    // so we need to decrement top first to fetch the actual top of the stack
    return *--top_ptr;
  }
}

void stack_overflow (void) {
  printf("[ERROR] Stack Already Filled.\n");
}

void stack_underflow (void) {
  printf("[ERROR] Stack Empty.\n");
}

