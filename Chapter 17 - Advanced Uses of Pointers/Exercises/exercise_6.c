// Q. Modify the delete_from_list function so that it uses only one pointer variable instead of two (cur and prev).
//
// Okay, some constraints need to be defined before we solve the problem:
//    1. The return type of the function delete_from_list (sll_delete_node in the program) must be void because the program utilizes the parameter list for traversing through the linked list.
//    2. The linked list fails to delete the first node, of the list. This means, the latest node added using the `n` command cannot be removed. The reason for this is, when we send the root pointer to the function sll_delete_node, we are passing a value--an address of the root node in the linked list--which cannot change the root node's address through the function call. Say that the root node's address is 0x1234, then when we pass it as an argument to the function, we are essentially initializing the list pointer with the address 0x1234. Now say that the first node needs to be deleted, that means that list = list->next. But this will only change the pointer variable list and not the root pointer variable. This can be solved if the function takes in pointer to a pointer to the type singly_linked_list_node, i.e. the function parameter should be `struct singly_linked_list_node **list`. By doing so, the address of the root pointer variable can be modified, but the issue is that the other nodes cannot be deleted with just one pointer variable as asked by the question. 

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

size_t num_nodes = 0;

typedef unsigned long size_t;

struct singly_linked_list_node {
  int num;
  struct singly_linked_list_node *next;
};

struct singly_linked_list_node *sll_initialize (int num);

struct singly_linked_list_node *sll_insert_node (struct singly_linked_list_node *list, int num);

struct singly_linked_list_node *sll_search_node (struct singly_linked_list_node *list, int num);

void sll_delete_node (struct singly_linked_list_node *list, int num);

void sll_clear_linked_list (struct singly_linked_list_node *list);

int sll_sort_num_comp_func (const void *element1, const void *element2);

void sll_sort_by_option (struct singly_linked_list_node *list);

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
        sll_delete_node(root, value);
        break;
      case 'o':
        sll_sort_by_option(root);
        break;
      case 'v':
        temp = root;
        if (temp == NULL) {
          fprintf(stderr, "[FATAL ERROR] The singly linked list is empty.\n");
          break;
        }
        printf("%15s    %10s      %15s\n", "Current Node Addresss", "Member: num", "Member: next (node address)");
        while (temp != NULL) {
          printf("%p              %5d              %p\n", (void *) temp, temp->num, (void *) temp->next);
          temp = temp->next;
        }
        break;
      case 'q':
        sll_clear_linked_list(root);
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

struct singly_linked_list_node *sll_initialize (int num) {
  struct singly_linked_list_node *root_node = NULL;
  struct singly_linked_list_node *new_node  = malloc(sizeof(struct singly_linked_list_node));

  if (new_node == NULL) {
    fprintf(stderr, "[ERROR] Call to malloc failed in sll_initialize.\n");
    exit(EXIT_FAILURE);
  }

  new_node->num   = num;
  new_node->next  = root_node;
  root_node       = new_node;

  num_nodes++;

  return root_node;
}

struct singly_linked_list_node *sll_insert_node (struct singly_linked_list_node *list, int num) {
  struct singly_linked_list_node *new_node = malloc(sizeof(struct singly_linked_list_node)); 

  if (new_node == NULL) {
    fprintf(stderr, "[ERROR] Call to malloc failed in sll_insert_node.\n");
    exit(EXIT_FAILURE);
  }

  new_node->num  = num;
  new_node->next = list;

  num_nodes++;
  
  return new_node;
}

struct singly_linked_list_node *sll_search_node (struct singly_linked_list_node *list, int num) {
  for (; list->next != NULL && list->num != num; list = list->next) {
    ;
  }

  return list;
}

// NOTE: The return type has been change from struct singly_linked_list_node *sll_delete_node to void since we would still be
// returning the list if it had a non-void return type, which is the argument that it was provided when called.
void sll_delete_node (struct singly_linked_list_node *list, int num) {
  struct singly_linked_list_node *node_ptr;

  // while (list != NULL) {
  //   if (list->num == num) {
  //     break;
  //   }
  //   node_ptr  = list;
  //   list      = list->next;
  // }

  for (; list != NULL; list = list->next) {
    if (list->num == num) {
      break;
    }
    node_ptr = list;
  }

  // The if condition will be executed if the list is NULL, i.e. the required num is not stored in the linked list
  // If the number has been found, the node_ptr will point to the node which is just previous to the one whose node is to be deleted.
  // Then the node_ptr->next will hold the pointer to the node that is just next to the node which needs to be deleted.
  // But it has a problem, the node that needs to be deleted is not freed.
  if (list == NULL) {
    printf("[ERROR] Provided Node doesn't exist.\n");
  } else {
    node_ptr->next = list->next;
    num_nodes--;
  }
}

void sll_clear_linked_list (struct singly_linked_list_node *list) {
  if (list == NULL) {
    return;
  }
  struct singly_linked_list_node *temp;
  for (; list != NULL;) {
    temp = list;
    list = list->next;
    free(temp);
  }
  return;
}

int sll_sort_num_comp_func (const void *element1, const void *element2) {
  const struct singly_linked_list_node **e1 = (const struct singly_linked_list_node **) element1;
  const struct singly_linked_list_node **e2 = (const struct singly_linked_list_node **) element2;

  if ((*e1)->num > (*e2)->num) {
    return 1;
  } else if ((*e1)->num == (*e2)->num) {
    return 0;
  } else {
    return -1;
  }
}

void sll_sort_by_option (struct singly_linked_list_node *list) {
  
  struct singly_linked_list_node *temp[num_nodes];

  size_t i = 0;

  while (list != NULL) {
    temp[i++] = list; 
    list = list->next;
  }

  qsort(temp, num_nodes, sizeof(struct singly_linked_list_node *), sll_sort_num_comp_func);

  printf("The sorted array is: \n");

  for (size_t j = 0; j < i; j++) {
    printf("Address of element %3zu and data %5d in list: %p\n", j, temp[j]->num, (void *) temp[j]);
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

