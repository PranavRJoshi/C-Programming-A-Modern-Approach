// Q. Section 15.2 describes a file, stack.c, that provides functions for storing integers in a stack. In that section, the stack was implemented as an array. Modify stack.c so that a stack is now stored as a linked list. Replace the contents and top variables by a single variable that points to the first node in the list (the "top" of the stack). Write the functions in stack.c so that they use this pointer. Remove the is_full function, instead having push return either true (if memory was available to create a node) or false (if not).

#include <stdio.h>
#include <stdlib.h>

struct stack_sll {
  int content;
  struct stack_sll *next;
};

struct stack_sll *push_stack_sll (struct stack_sll *s_list, int content);

int pop_stack_sll (struct stack_sll **s_list);

void view_stack_sll (struct stack_sll *s_list);

void clear_stack (struct stack_sll *s_list);

void clear_input_stream (void);

int main (void) {

  struct stack_sll *top = NULL;
  int content;

  char command;
  int scanf_return_count = 0;

  for (;;) {
    printf("A Program to add items in stack that is stored as linked list.\n"                 \
           "Description                     Command\n"                                        \
           "1. Push Content in Stack          a\n"                                            \
           "2. Pop Item From Stack            p\n"                                            \
           "3. View Current Stack             v\n"                                            \
           "4. Clear the Current Stack        c\n"                                            \
           "5. Quit the Program               q\n"                                            \
           "Enter command: ");

    for (;;) {
      if ((scanf_return_count = scanf(" %c", &command)) != 1) {
        printf("[ERROR] Insufficient Input Field Provided. Try Again.\n");
        clear_input_stream();
        continue;
      }
      scanf_return_count = 0;
      clear_input_stream();
      break;
    }

    switch (command) {
      case 'a':
        for (;;) {
          printf("Enter the content (int) to push into the stack: ");
          if ((scanf_return_count = scanf("%d", &content)) != 1) {
            printf("[ERROR] Insufficient Input Field Provided. Try Again.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        top = push_stack_sll(top, content);
        printf("[SUCCESS] %d was added to the top of the stack.\n", content);
        break;
      case 'p':
        content = pop_stack_sll(&top);
        printf("[SUCCESS] The popped Content is: %d\n", content);
        break;
      case 'v':
        view_stack_sll(top);
        break;
      case 'c':
        clear_stack(top);
        top = NULL;
        printf("[SUCCESS] Stack is cleared.\n");
        break;
      case 'q':
        clear_stack(top);
        top = NULL;
        exit(EXIT_SUCCESS);
      default:
        fprintf(stderr, "[ERROR] Invalid Command Entered. Try Again.\n");
    }
  }

  return 0;
}

struct stack_sll *push_stack_sll (struct stack_sll *s_list, int content) {
  struct stack_sll *temp;
  if (s_list == NULL) {
    temp = s_list;
    s_list = malloc(sizeof(struct stack_sll));
    if (s_list == NULL) {
      fprintf(stderr, "[ERROR] Failed to allocate memory for a node of type struct stack_sll in function: %s\n", __func__);
      return NULL;
    }
    s_list->content = content;
    s_list->next    = temp;
    return s_list;
  }
  temp = malloc(sizeof(struct stack_sll));
  if (temp == NULL) {
    fprintf(stderr, "[ERROR] Failed to allocate memory for a node of type struct stack_sll in function: %s\n", __func__);
    return NULL;
  }
  temp->content = content;
  temp->next    = s_list;

  return temp;
}

int pop_stack_sll (struct stack_sll **s_list) {
  if (*s_list == NULL) {
    fprintf(stderr, "[ERROR] Stack is empty.\n");
    exit(EXIT_FAILURE);
  }

  struct stack_sll *temp  = *s_list;
  int content             = (*s_list)->content;
  *s_list                 = (*s_list)->next;
  
  free(temp);
  
  return content;
}

void view_stack_sll (struct stack_sll *s_list) {
  if (s_list == NULL) {
    fprintf(stderr, "[WARN] Stack is currently empty. Push some items to view the contents.\n");
    return;
  }
  printf("Current Address       Content         Next Address\n"                   \
         "---------------     -----------      ----------------\n");
  while (s_list != NULL) {
    printf("%p        %5d           %p\n", (void *) s_list, s_list->content, (void *) s_list->next);
    s_list = s_list->next;
  }
}

void clear_stack (struct stack_sll *s_list) {
  struct stack_sll *temp = s_list;

  while (s_list != NULL) {
    s_list = s_list->next;
    free(temp);
    temp = s_list;
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

