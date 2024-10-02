// Q. The following function is supposed to insert a new node into its proper place in an ordered list, returning a pointer to the first node in the modified list. Unfortunately, the function doesn't work correctly in all cases. Explain what's wrong with it and show how to fix it. Assume that the node structure is the one defined in Section 17.5.
//    struct node *insert_into_ordered_list(struct node *list,
//                                          struct node *new_node)
//    {
//      struct node *cur = list, *prev = NULL;
//      while (cur->value <= new_node->value) {
//        prev = cur;
//        cur = cur->next;
//      }
//      prev->next = new_node;
//      new_node->next = cur;
//      return list;
//    }
//
// A. Consider a scenario where we call the function with root as the first argument and new_node as the second argument. Say that one function has the memory allocated for the new_node as follows:
//    void create_new_node (...) {
//      struct node *new_node;
//      new_node = malloc(sizeof(struct node));
//      new_node->value = ...;
//      struct node *temp;
//      temp = insert_into_ordered_list(root, new_node);
//    }
// When we call the function in this manner, the function parameter:
//    1. list will hold the pointer to the struct node variable root, and,
//    2. new_node will hold the pointer to the struct node variable new_node--defined in create_new_node.
//
// One of the problem of the program is that say that we have a linked list of data: 5, 10. The new value we need to store is 15. 
// What will happen is:
//    1. (5 <= 15) is true, so prev will now point to address pointed to by cur, and cur will point to address pointed to by cur->next--which holds the value 10.
//    2. (10 <= 15) is true, so prev will point to node which contains the value 10, and cur will point to the NULL pointer, assuming that the end of the linked list has the NULL node.
//    3. (cur->value <= 15) is evaluated, the expression is not valid as it is trying to access the memory pointed by a NULL pointer, which is a ERR_BAD_ACCESS. 
//
// To fix this problem, we must have the condition for the while statement as follows:
//    while (cur != NULL && cur->value <= new_node->value);
// Notice that the first expression (cur != NULL) preceeds the given expression (cur->value <= new_node->value). This is done to conform to the short circuiting functionality provided by C. If the first expression is false, lazy evaluation takes places as 0 && anything will result in 0.
// This will fix the issue of adding nodes in the list. BUT, this does not solve the problem of adding the node whose value is smaller as compared to other node's value. In such case, the new_node should be added first, which is not the behavior of this program.
// To solve this, the following modification needs to be done:
//    if (prev == NULL) {
//      new_node->next = cur;
//      return new_node;
//    } else {
//      prev->next      = new_node;
//      new_node->next  = cur;
//      return list;
//    }
// If the new_node contains the value which is lower as compared to other node's value, then the while loop will not run, making prev still point to NULL as it was initialized. Then, the new_node can be modified to act as the first node in the linked list. If not, and the new_node is the one which is to be added between the list or at the end, the else clause will run, and the desired effect is noticed.

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
 * sll_find_last: Searches the list for the provided num, and returns the address of the last node 
 *                which contains the provided num.
*/
struct singly_linked_list_node *sll_find_last (struct singly_linked_list_node *list, int num);

/*
 * sll_insert_into_ordered_list:  Takes the root node as the first argument, and the node to be added as the second argument.
 *                                Inserts the node in the ascending order based on the member num of the structure singly_linked_list_node
*/
struct singly_linked_list_node *sll_insert_into_ordered_list (struct singly_linked_list_node *list, struct singly_linked_list_node *new_node);

void clear_input_stream (void);

int main (void) {

  int command;
  int scanf_return_count = 0;
  int value;
  /* For finding the last occurance of a number */
  int num_to_search;
  struct singly_linked_list_node *occ_addr = NULL;
  struct singly_linked_list_node *new_node = NULL;

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
           "6. Find last Occurance                            (l)\n"                                      \
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
        // root = sll_insert_node(root, value);
        new_node = malloc(sizeof(struct singly_linked_list_node));
        if (new_node == NULL) {
          fprintf(stderr, "[ERROR] Failed to Allocate Memory for a New Node.\n");
        }
        new_node->num = value;
        /* EXERCISE: Sorted Insertion in Linked List. */
        root = sll_insert_into_ordered_list(root, new_node);
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
      case 'l':
        for (;;) {
          printf("Enter the number to count its occurrences: ");
          if ((scanf_return_count = scanf("%d", &num_to_search)) != 1) {
            fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
            clear_input_stream();
            continue;
          }
          scanf_return_count = 0;
          clear_input_stream();
          break;
        }
        occ_addr = sll_find_last(root, num_to_search);
        if (occ_addr == NULL) {
          printf("[WARN] The provided number (%d) is not present in the linked list.\n", num_to_search);
        } else {
          printf("[SUCCESS] %d is found and the address of it's last occurrence in the linked list is: %p\n", num_to_search, (void *) occ_addr);
        }
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

struct singly_linked_list_node *sll_insert_into_ordered_list (struct singly_linked_list_node *list, struct singly_linked_list_node *new_node) {
  struct singly_linked_list_node *cur = list, *prev = NULL;
  // struct singly_linked_list_node *prev = NULL;
  // printf("[LOG] The address of cur is: %p\n", (void *) cur);
  // printf("[LOG] The content of cur->num is: %d\n", cur->num);
  // printf("[LOG] The content of new_node->num is: %d\n", new_node->num);
  while (cur != NULL && cur->num <= new_node->num) {
    // printf("[LOG] The cur variable and its content is:\nnum: %d\nnext: %p", cur->num, (void *) cur->next);
    prev  = cur;
    cur   = cur->next;
  }
  if (prev == NULL) {
    new_node->next = cur;
    return new_node;
  } else {
    prev->next      = new_node;
    new_node->next  = cur;
    return list;
  }
}

// struct singly_linked_list_node *sll_insert_node (struct singly_linked_list_node *list, int num) {
//   struct singly_linked_list_node *new_node = malloc(sizeof(struct singly_linked_list_node)); 
//
//   if (new_node == NULL) {
//     fprintf(stderr, "[ERROR] Call to malloc failed in sll_insert_node.\n");
//     exit(EXIT_FAILURE);
//   }
//
//   new_node->num  = num;
//   new_node->next = list;
//
//   num_nodes++;
//   
//   return new_node;
// }

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

struct singly_linked_list_node *sll_find_last (struct singly_linked_list_node *list, int num) {
  struct singly_linked_list_node *temp = NULL;

  while (list != NULL) {
    if (list->num == num) {
      temp = list;
    }
    list = list->next;
  }

  return temp;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

