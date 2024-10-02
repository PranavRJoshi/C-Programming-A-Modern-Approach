#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

// #include <stdio.h>

typedef unsigned long size_t;

struct singly_linked_list_node {
  int num;
  struct singly_linked_list_node *next;
};

/*
 * sll_initalize: allocates memory for the struct singly_linked_list_node (node)
 *                and stores the num in the first node. Returns the address of the
 *                newly created node. If the program can't allocate space, then terminates.
*/
struct singly_linked_list_node *sll_initialize (int num);

/*
 * sll_insert_node: inserts the given num into the singly_linked_list_node pointer list,
 *                  and returns the modified list. Exits if it can't allocate more storage 
 *                  to insert a new node.
*/
struct singly_linked_list_node *sll_insert_node (struct singly_linked_list_node *list, int num);

/*
 * sll_search_node: searches for the node that has the num integer as it's node's content.
 *                  If there does not exist such node, returns the final address, whose next member 
 *                  contains the NULL pointer. If searched successfully for the num, returns the address 
 *                  of the node that contains the num as it's content.
*/
struct singly_linked_list_node *sll_search_node (struct singly_linked_list_node *list, int num);

/*
 * sll_delete_node: removes a node from the singly_linked_list_node struct and the previous node 
 *                  will have the next member point to the node that is just after the node that is
 *                  being removed. If the removed node is the last node, the previous node to it will
 *                  point to the null pointer.
*/
struct singly_linked_list_node *sll_delete_node (struct singly_linked_list_node *list, int num);

/*
 * sll_clear_linked_list: Clears the given list variable by free-ing up each node, until the final node is
 *                        reached, where the next member points to the NULL pointer.
*/
void sll_clear_linked_list (struct singly_linked_list_node *list);

/*
 * sll_sort_num_comp_func:  Acts as a "helper" function that is passed to qsort as comparision function
 *                          which sorts the linked list. The arguments to this function is essentially 
 *                          the pointer to the array elements. Returns 1, 0, or -1 according to the 
 *                          type of comparision done.
*/
int sll_sort_num_comp_func (const void *element1, const void *element2);

/*
 * sll_sort_by_option:  As the struct only has one member (an integer), we need not have
 *                      an option for now. The function takes list as an argument. An array 
 *                      is declared which will contain the addresses of the nodes which is 
 *                      passed to qsort. Calls the qsort function which has the argument 
 *                      sll_sort_num_comp_func and then returns an array that will be in 
 *                      sorted order. Does not affect the original linked list.
*/
void sll_sort_by_option (struct singly_linked_list_node *list);

#endif

