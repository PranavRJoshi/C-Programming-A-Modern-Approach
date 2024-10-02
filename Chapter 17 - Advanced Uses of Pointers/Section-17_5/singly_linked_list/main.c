#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "singly_linked_list.h"

void clear_input_stream (void);

int main (void) {

  int command;
  int scanf_return_count = 0;
  int value;

  struct singly_linked_list_node *root = NULL;
  struct singly_linked_list_node *searched_node = NULL;
  struct singly_linked_list_node *temp = NULL;

  for (;;) {
    printf("A simple program that provides the following operations on singly linked list.\n"             \
           "NOTE: The linked list only has one member: int num.\n"                                        \
           "      Usage                                     Command\n"                                    \
           "1. Initilize a Singly Linked List                 (i)\n"                                      \
           "2. Add a new node in the beginning of list        (n)\n"                                      \
           "3. Search for a node                              (s)\n"                                      \
           "4. Delete a node                                  (d)\n"                                      \
           "5. Sort the nodes                                 (o)\n"                                      \
           "6. View all nodes                                 (v)\n"                                      \
           "7. Terminate the program                          (q)\n"                                      \
           "Enter command: ");
    while (isspace(command = getchar())) {
      ;
    }

    clear_input_stream();
    
    switch (command) {
      case 'i':
        for (;;) {
          printf("Enter the number to store: ");
          if ((scanf_return_count = scanf(" %d", &value)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        root = sll_initialize(value);
        break;
      case 'n':
        if (root == NULL) {
          fprintf(stderr, "[FATAL ERROR] No node has been initialized.\n");
          break;
        }
        for (;;) {
          printf("Enter the number to store: ");
          if ((scanf_return_count = scanf(" %d", &value)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        root = sll_insert_node(root, value);
        break;
      case 's':
        if (root == NULL) {
          fprintf(stderr, "[FATAL ERROR] No node has been initialized.\n");
          break;
        }
        for (;;) {
          printf("Enter the number to search in the list: ");
          if ((scanf_return_count = scanf(" %d", &value)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        // searched_node = malloc(sizeof(struct singly_linked_list_node));
        // if (searched_node == NULL) {
        //   fprintf(stderr, "[ERROR] Call to malloc failed in main, when initializing searched_node.\n");
        //   break;
        // }
        searched_node = sll_search_node(root, value);
        if (searched_node->next == NULL && searched_node->num != value) {
          printf("[WARN] The given number is not currently in the list.\n");
        }
        if (searched_node->num == value) {
          printf("The node has the following members:\n"                                                              \
                 "int num                               = %d\n"                                                       \
                 "struct singly_linked_list_node *next  = %p\n", searched_node->num, (void *) searched_node->next);
        }
        // free(searched_node);
        break;
      case 'd':
        if (root == NULL) {
          fprintf(stderr, "[FATAL ERROR] No node has been initialized.\n");
          break;
        }
        for (;;) {
          printf("Enter the number to search in the list: ");
          if ((scanf_return_count = scanf(" %d", &value)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        root = sll_delete_node(root, value);
        break;
      /* qsort application: Section 17.7 */
      case 'o':
        sll_sort_by_option(root);
        break;
      case 'v':
        temp = root;
        if (temp == NULL) {
          fprintf(stderr, "[FATAL ERROR] The singly linked list is empty.\n");
          break;
        }
        // printf("The root node has the address: %p\n\n", (void *) &temp);
        printf("%15s    %10s      %15s\n", "Current Node Addresss", "Member: num", "Member: next (node address)");
        while (temp != NULL) {
          // printf("The members are:\n"                                                           \
          //        "int num                         = %d\n"                                       \
          //        "struct singly_linked_list_node  = %p\n\n", temp->num, (void *) temp->next);
          printf("%p              %d            %p\n", (void *) temp, temp->num, (void *) temp->next);
          temp = temp->next;
        }
        break;
      case 'q':
        /* The reason we need to free root and not other variables is we only used root 
         * to dynamically allocate storage, not others. When the initialize command or
         * new node command is selected, there is the process of allocating memory using
         * malloc, so we need to use free to free the variable.
        */
        sll_clear_linked_list(root);
        // The reason root won't be freed, i.e. root == NULL, is beacuse when we pass it to the function above,
        // *list = root, where *list is the function parameter, so we're essentially passing it as a "value".
        // Inside the function, *list is again assigned the next member of the nodes, but in essence, root is remaining as is.
        // To overcome this, we can essentially assign root to NULL here. (or we can pass a pointer to the root variable and free it inside the function itself.)
        // printf("The address stored in root is: %p\n", (void *) root);
        root = NULL;
        searched_node = NULL;
        temp = NULL;
        exit(EXIT_SUCCESS);
      default:
        printf("[ERROR] Invalid Command Entered.\n");
    }
  }
  return 0;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}
