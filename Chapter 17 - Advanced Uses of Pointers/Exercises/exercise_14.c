// Q. Modify the delete_from_list function (Section 17.5) so that its first parameter has type struct node ** (a pointer to a pointer to the first node in a list) and its return type is void. delete_from_list must modify its first argument to point to the list after the desired node has been deleted.
//
// NOTE: Take reference from the function definition sll_delete_node
// One way to visualize this is, consider that the first node in the linked list, pointed to by root is:
//    1. address of first node--of type struct singly_linked_list_node--has the address: 0x1234.
//    2. root is, say, in address 0x5678, whose content is 0x1234.
//    3. When sending the address of root, what we're essentially doing is, we're sending 0x5678 in the function.
// When the first node is the one that needs to be deleted, prev will be NULL. Keep in mind the following assignments to the function parameters:
//    1. list is a pointer to a pointer to a struct singly_linked_list_node variable, which will be the address of root in this case.
//    2. num is a number that needs to be checked in the linked list to delete the respective node.
// When the first node is to be deleted, `*list = (*list)->next` is done. What this does is, as list is 0x5678, dereferencing it will point to the address 0x1234, and (*list)->next is the one next to the first pointer. What is essentially happening here is, we're changing the address of the first node with the address of the node which is being pointed to by the member of the first node's next member.

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

void sll_delete_node (struct singly_linked_list_node **list, int num);

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
           ">> Enter command: ");
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
        sll_delete_node(&root, value);
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
          printf("%p              %5d            %p\n", (void *) temp, temp->num, (void *) temp->next);
          temp = temp->next;
        }
        break;
      case 'q':
        sll_clear_linked_list(root);
        root          = NULL;
        searched_node = NULL;
        temp          = NULL;
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

void sll_delete_node (struct singly_linked_list_node **list, int num) {
  struct singly_linked_list_node *prev, *curr;

  for (curr = *list, prev = NULL; curr != NULL && curr->num != num; prev = curr, curr = curr -> next) {
    ;
  }

  if (curr == NULL) {
    return;
  }
  
  if (prev == NULL) {
    *list = (*list)->next;
  } else {
    prev->next = curr->next;
  }

  free(curr);
  num_nodes--;
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
    list      = list->next;
  }

  qsort(temp, num_nodes, sizeof(struct singly_linked_list_node *), sll_sort_num_comp_func);

  printf("The sorted array is: \n");

  for (size_t j = 0; j < i; j++) {
    printf("Address of element %zu and data %d in list: %p\n", j, temp[j]->num, (void *) temp[j]);
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

