// Let's redo the parts database program of Section 16.3, this time storing the database in a linked list. Using a linked list instead of an array has two major advantages:
//    1. We don't need to put a preset limit on the size of the database; it can grow until there's no more memory to store parts.
//    2. We can easily keep the database sorted by the part number--when a new part is added to the database, we simply insert it in its proper place in the list.
// In the original program, database wasn't sorted.
//
// In the new program, the part structure will contain an additional member pointer (a pointer to the next node in the linked list), and the variable inventory will be a pointer to the first node in the list:
//    struct part {
//      int number;
//      char name[NAME_LEN + 1];
//      int on_hand;
//      struct part *next;
//    };
// 
// struct part *inventory = NULL;     /* points to the first part */
// 
// Most of the functions in the program will closely resemble their counterparts in the original program. The find_part and insert functions will be more complex, however, since we'll keep the nodes in the inventory list sorted by a part number.
//
// In the original program, find_part returns an index into the inventory array. In the new program, find_part will return a pointer to the node that contains the desired part number. If it doesn't find the part number, find_part will return a null pointer. Since the inventory list is sorted by part number, the new version of find_part can save time by stopping its search when it finds a node containing a part number that's greater than or equal to the desired part number. find_part's search loop will have the form
//    for (p = inventory; p != NULL && number > p->number; p = p->next)
//      ;
// 
// The loop will terminate when p becomes NULL (indicating that the part number wasn't found) or when number > p->number is false (indicating that the part number we're looking for is less than or equal to a number already stored in a node). In the latter case, we still don't know whether or not the desired number is actually in the list, so we'll need another test:
//    if (p != NULL && number == p->number)
//      return p;
// 
// The original version of insert stores a new part in the next available array element. The new version must determine where the new part belongs in the list and insert it there. We'll also have insert check whether the part number is already present in the list, insert can accomplish both tasks by using a loop similar to the one in find_part:
//    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next)
//      ;
// 
// This loop relies on two pointers: cur, which points to the current node, and prev, which points to the previous node. Once the loop terminates, insert will check whether cur isn't NULL and new_node->number equals cur->number; if so, the part number is already in the list. Otherwise insert will insert a new node between the nodes pointed to by prev and cur, using a strategy similar to the one we employed for deleting a node. (This strategy works even if the new part number is larger than any in the list; in that case, cur will be NULL but prev will point to the last node in the list.)
//
// Here's the new program. Like the original program, this version requires the read_line function described in Section 16.3; I assume that readline.h contains a prototype for this function.

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;      /* points to first part */

/*
 * find_part:   Looks up a part number in the inventory list.
 *              Returns a pointer to the node containing the 
 *              part number; if the part number is not found,
 *              returns NULL.
*/
struct part *find_part (int number);

/*
 * insert:  Prompts the user for information about a new part and then
 *          inserts the part into the inventory list; the list remains
 *          sorted by part number. Prints an error message and returns 
 *          prematurely if the part already exists or space could not 
 *          be allocated for the part.
*/
void insert (void);

/*
 * search:  Prompts the user to enter a part number, then looks up the 
 *          part in the database. If the part exists, prints the name
 *          and quantity on hand; if not, prints an error message.
*/
void search (void);

/*
 * update:  Prompts the user to enter a part number. Prints an error
 *          message if the part doesn't exist; otherwise, prompts the
 *          user to enter change in quantity on hand and updates the 
 *          database.
*/
void update (void);

/*
 * print: Prints a listing of all parts in the database, showing the 
 *        part number, part name, and quantity on hand. Part numbers 
 *        will appear in ascending order.
*/
void print (void);

/*
 * clear_input_stream:  Clears the input stream and terminates when it
 *                      encounters a new-line character or EOF.
*/
void clear_input_stream (void);

int main (void) {
  char code;

  for (;;) {
    printf("    Usage                   Command\n"                            \
           "1. Insert a new part          (i)\n"                              \
           "2. Update a part              (u)\n"                              \
           "3. Search for a part          (s)\n"                              \
           "4. Print the parts            (p)\n"                              \
           "5. Quit the program           (q)\n"                              \
           "Enter operation code: ");
    scanf(" %c", &code);

    while (getchar() != '\n') {
      ;         /* skips to end of line */
    }

    switch (code) {
      case 'i':   
        insert();
        break;
      case 's':
        search();
        break;
      case 'u':
        update();
        break;
      case 'p':
        print();
        break;
      case 'q':
        return 0;
      default:
        printf("[ERROR] Illegal Code.\n");
    }

    printf("\n");
  }
}

struct part *find_part (int number) {
  struct part *p;

  for (p = inventory; p != NULL && number > p->number; p = p->next) {
    ;
  }

  if (p != NULL && number == p->number) {
    return p;
  }

  return NULL;
}

void insert (void) {
  struct part *cur, *prev, *new_node;

  int scanf_return_count = 0;

  new_node = malloc(sizeof(struct part));

  if (new_node == NULL) {
    fprintf(stderr, "[ERROR] Database is full; can't add more parts.\n");
    return;
  }

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &new_node->number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next) {
    ;
  }

  if (cur != NULL && new_node->number == cur->number) {
    printf("Parts already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);

  for (;;) {
    printf("Enter quantity on hand: ");
    if ((scanf_return_count = scanf("%d", &new_node->on_hand)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  new_node->next = cur;

  // When a first node is being added, prev will be NULL, and so, inventory will hold the pointer to the new_node
  // that contains the information for the parts that was input from the user.
  // If there are other parts, then prev will not be NULL, rather, it will be a pointer to the node in the list
  // where the next node (cur) has the number member that is greater than the parts number that is taken from the 
  // input. Hence, we will insert the pointer to the new_node to the prev->next member. NOTE: the above assignment
  // of new_node->next = cur ensures that the the pointer to the cur is assigned to the next member in new_node,
  // hence making a chain that is required.
  if (prev == NULL) {
    inventory = new_node;
  } else {
    prev->next = new_node;
  }
}

void search (void) {
  int number;
  struct part *p;

  int scanf_return_count = 0;

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  p = find_part(number);

  if (p != NULL) {
    printf("Part Name: %s\n"                                \
           "Quantity on hand: %d\n", p->name, p->on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void update (void) {
  int number, change;
  struct part *p;

  int scanf_return_count = 0;

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  p = find_part(number);

  if (p != NULL) {
    for (;;) {
      printf("Enter change in quantity on hand: ");
      if ((scanf_return_count = scanf("%d", &change)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
      }
      scanf_return_count = 0;
      clear_input_stream();
      break;
    }
    p->on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print (void) {
  struct part *p;

  printf("Part Number     Part Name                         "                       \
         "Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next) {
    printf("%7d         %-25s     %11d\n", p->number, p->name, p->on_hand);
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

// Notice the use of free in the insert function. insert allocates memory for a part before checking it to see if the part already exists. If it does, insert releases the space to avoid a memory leak.
