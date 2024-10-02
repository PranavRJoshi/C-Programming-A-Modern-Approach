#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "singly_linked_list.h"

size_t num_nodes = 0;

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
  /* Out of the three statements in the for loop, the first one is not present, which is usually
   * the statement that initializes the loop.
   *
   * The second statement has two expressions binded by a logical AND operator. The first expression
   * checks if the next member of the list node is NULL or not. If it is NULL, it will terminate the for 
   * loop (without checking the second expression as C's has short circuit tecnique.). The second expression 
   * will check if the node's num member equate to the num that was provided as the argument during the 
   * function call. If this is false, i.e. list->num == num, then the loop terminates.
   *
   * The third statement is just used to list point to the next node from the node's next member.
  */
  for (; list->next != NULL && list->num != num; list = list->next) {
    ;
  }

  return list;
}

struct singly_linked_list_node *sll_delete_node (struct singly_linked_list_node *list, int num) {
  struct singly_linked_list_node *prev, *curr;

  /* The first statment has two expressions: the first expression assigns the address of list to the
   * singly_linked_list_node struct pointer variable curr and the second expression assigns the 
   * NULL address ((void *) 0) to the singly_linked_list_node struct pointer variable prev.
   *
   * The second statement checks whether curr has the address NULL, which is the case when the node traverses
   * through the entire list where the last node has the next member pointing to NULL pointer/address.
   * Along with that, it also checks if the current node's num member (curr->num) is equal to the num that 
   * was passed to the function as an argument. If this is true, it means that the curr pointer variable is the one
   * we wish to delete from the list. And so, the loop terminates, whilst curr pointing to the node that will be terminated
   * and the prev pointer variable pointing to the node just before the node that curr is pointing to.
   *
   * The third statement will be executed after each iteration. There are two expressions, the first expression
   * will assign the pointer to the node that curr is pointing to, to the pointer variable prev. The second expression 
   * will assign curr, a pointer variable, the pointer that is present in the next member of the node structure.
  */
  for (curr = list, prev = NULL; curr != NULL && curr->num != num; prev = curr, curr = curr -> next) {
    ;
  }

  /* Case: The node which contains num was not found. */
  if (curr == NULL) {
    return list;
  }
  
  /* Case: The node which contains num is the first node. */
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
  /* Case: When the given list is an empty list, do nothing. */
  if (list == NULL) {
    return;
  }
  struct singly_linked_list_node *temp;
  /* Traverses through each nodes and clears the nodes while list will be pointing to the next node. */
  for (; list != NULL;) {
    temp = list;
    list = list->next;
    free(temp);
  }
  return;
}

int sll_sort_num_comp_func (const void *element1, const void *element2) {
  /* NOTE:  One thing to keep in mind is that the conversion function has the parameters which represents the 
   *        address of the array elements. Since we are sending it an array that contains the address of nodes--
   *        which is like saying `struct singly_linked_list_node **` type as when we dereference it one time, we 
   *        get the content stored in that address which is the address of the node. It is similar to making array
   *        of strings, where we initialized the variable as `char *var[10] = {...}`, which is the same as writing
   *        `char **var = {...}`. So, after converting the void address to the type which we can operate on,
   *        then we need to first dereference the element's address to get the address of the nodes, then only 
   *        we can use the struct operators like -> to access the struct members.
  */

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

  // printf("The addresses of the linked list are: \n");
  //
  // for (size_t j = 0; j < i; j++) {
  //   printf("Address of element %zu in list: %p\n", j, (void *) temp[j]);
  // }

  qsort(temp, num_nodes, sizeof(struct singly_linked_list_node *), sll_sort_num_comp_func);

  printf("The sorted array is: \n");

  for (size_t j = 0; j < i; j++) {
    printf("Address of element %zu and data %d in list: %p\n", j, temp[j]->num, (void *) temp[j]);
  }
}

