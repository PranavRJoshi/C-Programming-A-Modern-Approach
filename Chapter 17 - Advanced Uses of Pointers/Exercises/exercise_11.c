// Q. Write the following function:
//    int count_occurrences (struct node *list, int n);
// The list parameter points to a linked list; the function should return the number of times that n appears in this list. Assume that the node structure is the one defined in Section 17.5.
//
// The program utilizes the code that was written in Section 17.5, with the modification as required by the question.
// The program is not split into multiple files for simplicity purposes, contrary to the one written in Section 17.5.

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

struct singly_linked_list_node *sll_delete_node (struct singly_linked_list_node *list, int num);

void sll_clear_linked_list (struct singly_linked_list_node *list);

int sll_sort_num_comp_func (const void *element1, const void *element2);

void sll_sort_by_option (struct singly_linked_list_node *list);

/*
 * sll_count_occurrences: Counts the number of occurrences of num in the singly linked
 *                        list called list. If the number does not occur in the list,
 *                        returns zero.
*/
int sll_count_occurrences (struct singly_linked_list_node *list, int num);

void clear_input_stream (void);

int main (void) {

  int command;
  int scanf_return_count = 0;
  int value;
  /* For counting the occurrences of a number */
  int count_occurrences;
  int occurrences_num;

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
           "6. Count Occurrences                              (c)\n"                                      \
           "7. View all nodes                                 (v)\n"                                      \
           "8. Terminate the program                          (q)\n"                                      \
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
        root = sll_delete_node(root, value);
        break;
      case 'o':
        sll_sort_by_option(root);
        break;
      case 'c':
        for (;;) {
          printf("Enter the number to count its occurrences: ");
          if ((scanf_return_count = scanf("%d", &occurrences_num)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        count_occurrences = sll_count_occurrences(root, occurrences_num);
        printf("Total Occurances of %d in singly linked list: %d\n", occurrences_num, count_occurrences);
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

struct singly_linked_list_node *sll_delete_node (struct singly_linked_list_node *list, int num) {
  struct singly_linked_list_node *prev, *curr;

  for (curr = list, prev = NULL; curr != NULL && curr->num != num; prev = curr, curr = curr -> next) {
    ;
  }

  if (curr == NULL) {
    return list;
  }
  
  if (prev == NULL) {
    list = list->next;
  } else {
    prev->next = curr->next;
  }

  free(curr);
  num_nodes--;

  return list;
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

int sll_count_occurrences (struct singly_linked_list_node *list, int num) {
  int count = 0;

  while (list != NULL) {
    if (list->num == num) {
      count++;
    }
    list = list->next;
  }

  return count;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

