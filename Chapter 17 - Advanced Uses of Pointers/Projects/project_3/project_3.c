// Q. Modify the inventory2.c program of Section 17.5 by adding an e (erase) command that allows the user to remove a part from the database.

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

/*
 * TAKE_INPUT:  Takes input for n variables, displays the p prompt
 *              to the user, and remaining arguments are used for 
 *              scanf to store the input to the variables from the 
 *              input stream.
*/
#define TAKE_INPUT(n, p, ...)                                             \
for (;;) {                                                                \
  printf((p));                                                            \
  if ((scanf(__VA_ARGS__)) != (n)) {                                      \
    fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");      \
    while ((getchar()) != '\n') {                                         \
      ;                                                                   \
    }                                                                     \
    continue;                                                             \
  }                                                                       \
  break;                                                                  \
}

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
 * erase: asks the user for the part number, locates the node with the
 *        corresponding part number, and removes it from the linked list
*/
void erase (void);

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
           "5. Erase a part               (e)\n"                              \
           "6. Quit the program           (q)\n"                              \
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
      case 'e':
        erase();
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

  // int scanf_return_count = 0;

  new_node = malloc(sizeof(struct part));

  if (new_node == NULL) {
    fprintf(stderr, "[ERROR] Database is full; can't add more parts.\n");
    return;
  }

  TAKE_INPUT(1, "Enter Part Number: ", "%d", &new_node->number);
  // for (;;) {
  //   printf("Enter part number: ");
  //   if ((scanf_return_count = scanf("%d", &new_node->number)) != 1) {
  //     fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
  //     clear_input_stream();
  //     continue;
  //   }
  //   scanf_return_count = 0;
  //   clear_input_stream();
  //   break;
  // }

  for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next) {
    ;
  }

  if (cur != NULL && new_node->number == cur->number) {
    printf("Parts already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter Part Name: ");
  read_line(new_node->name, NAME_LEN);

  TAKE_INPUT(1, "Enter quantity on hand: ", "%d", &new_node->on_hand);
  // for (;;) {
  //   printf("Enter quantity on hand: ");
  //   if ((scanf_return_count = scanf("%d", &new_node->on_hand)) != 1) {
  //     fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
  //     clear_input_stream();
  //     continue;
  //   }
  //   scanf_return_count = 0;
  //   clear_input_stream();
  //   break;
  // }

  new_node->next = cur;

  if (prev == NULL) {
    inventory = new_node;
  } else {
    prev->next = new_node;
  }
}

void search (void) {
  int number;
  struct part *p;

  // int scanf_return_count = 0;

  TAKE_INPUT(1, "Enter Part Number: ", "%d", &number);
  // for (;;) {
  //   printf("Enter part number: ");
  //   if ((scanf_return_count = scanf("%d", &number)) != 1) {
  //     fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
  //     clear_input_stream();
  //     continue;
  //   }
  //   scanf_return_count = 0;
  //   clear_input_stream();
  //   break;
  // }

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

  // int scanf_return_count = 0;

  TAKE_INPUT(1, "Enter Part Number: ", "%d", &number);
  // for (;;) {
  //   printf("Enter part number: ");
  //   if ((scanf_return_count = scanf("%d", &number)) != 1) {
  //     fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
  //     clear_input_stream();
  //     continue;
  //   }
  //   scanf_return_count = 0;
  //   clear_input_stream();
  //   break;
  // }

  p = find_part(number);

  if (p != NULL) {
    TAKE_INPUT(1, "Enter change in quantity on hand: ", "%d", &change);
    // for (;;) {
    //   printf("Enter change in quantity on hand: ");
    //   if ((scanf_return_count = scanf("%d", &change)) != 1) {
    //   fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
    //   clear_input_stream();
    //   continue;
    //   }
    //   scanf_return_count = 0;
    //   clear_input_stream();
    //   break;
    // }
    p->on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print (void) {
  struct part *p = inventory;

  if (p == NULL) {
    fprintf(stderr, "[ERROR] List is currently empty.\n");
    return;
  }

  printf("Current Address       Part Number     Part Name         Quantity on Hand        Next Address\n");
  for (; p != NULL; p = p->next) {
    printf("%p      %7d           %-15s     %5d                 %p\n", (void *) p, p->number, p->name, p->on_hand, (void *) p->next);
  }
}

void erase (void) {
  
  int scanf_return_count = 0;

  int erasing_part_number;
  struct part *erasing_node = NULL;

  for (;;) {
    printf("Enter the part number to erase: ");
    if ((scanf_return_count = scanf("%d", &erasing_part_number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    if ((erasing_node = find_part(erasing_part_number)) == NULL) {
      fprintf(stderr, "[ERROR] Provided part number does not exist. Try Again.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }
  
  struct part *cur = inventory, *prev = NULL;

  for (; cur != erasing_node; prev = cur, cur = cur->next) {
    ;
  }

  printf("The address of erasing node is: %p and cur is: %p\n", (void *) erasing_node, (void *) cur);

  /* a case when the node that needs to be erased is the first node */
  if (prev == NULL) {
    inventory = inventory->next;
    free(cur);
    cur = NULL;
    return;
  }

  prev->next = cur->next;
  free(cur);
  cur = NULL;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

