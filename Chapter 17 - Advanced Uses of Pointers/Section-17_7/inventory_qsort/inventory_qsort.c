#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_PARTS 100
#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

/*
 * find_part: Looks up part number in the inventory
 *            array. Returns the array index if the part
 *            number is found; otherwise, returns -1
*/
int find_part (int number);

/*
 * insert:  Prompts the user for information about a new part
 *          and then inserts the part into the database. Prints
 *          an error message and returns prematurely if the part
 *          already exists or the database is full.
*/
void insert (void);

/*
 * search:  Prompts the user to enter a part number, then
 *          looks up the part in the database. If the part
 *          exists, prints the name and quantity on hand;
 *          if not, prints an error message
*/
void search (void);

/*
 * update:  Prompts the user to enter a part number.
 *          Prints an error message if the part doesn't 
 *          exist; otherwise, prompts the user to enter
 *          change in quantity on hand and updates the
 *          database
*/
void update (void);

/*
 * sort:  Sorts the inventory arrays provided the sorting option.
*/
void sort (void);

/*
 * print: Prints a listing of all parts in the database
 *        in sorted order showing the part number, 
 *        part name, and quantity on hand. Parts are 
 *        printed in the order in which they were entered 
 *        into the database
*/
void print (void);

/*
 * clear_input_stream:  Clears the input stream and terminates when it
 *                      encounters a new-line character or EOF.
*/
void clear_input_stream (void);

/*
 * comp_parts_by_number:  Takes two void pointers as argument and casts it into
 *                        struct part * type which is required to compare the number 
 *                        member between p and q. Comparision is done to sort in the 
 *                        ascending order.
*/
int comp_parts_by_number (const void *p, const void *q);

/*
 * comp_parts_by_name:  Takes two void pointers as argument and casts it into struct part * 
 *                      type which is required to compare the name member between p and q.
 *                      Calls the my_strcmp function to compare the strings and the comparision
 *                      is done to sort in the ascending order.
*/
int comp_parts_by_name (const void *p, const void *q);

/*
 * comp_parts_by_on_hand: Takes two void pointers as arguments which is later casted to type of 
 *                        struct part *. Later, the on_hand member of p and q are compared so as 
 *                        to sort the inventory array in descending order.
*/
int comp_parts_by_on_hand (const void *p, const void *q);

/*
 * my_strcmp: Takes two strings as arguments, and if the strings are same, returns 0, else returns
 *            the ASCII code difference between the first unequal character of second_string from 
 *            the first_string.
*/
int my_strcmp (const char *first_string, const char *second_string);

int main (void) {
  char code;

  for (;;) {
    printf("    Usage                   Command\n"                            \
           "1. Insert a new part          (i)\n"                              \
           "2. Update a part              (u)\n"                              \
           "3. Search for a part          (s)\n"                              \
           "4. Sort inventory             (o)\n"                              \
           "5. Print the parts (sorted)   (p)\n"                              \
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
      case 'o':
        sort();
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

int find_part (int number) {
  int i;

  for (i = 0; i < num_parts; i++) {
    if (inventory[i].number == number) {
      return i;
    }
  }

  return -1;

}

void insert (void) {
  int part_number;
  int scanf_return_count = 0;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &part_number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  for (;;) {
    printf("Enter quantity on hand: ");
    if ((scanf_return_count = scanf("%d", &inventory[num_parts].on_hand)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;

    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }
  num_parts++;
}

void search (void) {
  int i, number;
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

  i = find_part(number);

  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void sort (void) {
  char option;

  printf("The following sorting are currently avaiable:\n"                                    \
         "    Sort By                         Command\n"                                      \
         "1. Part Number  (ascending)           (a)\n"                                        \
         "2. Part Name    (ascending)           (b)\n"                                        \
         "3. On Hand      (descending)          (c)\n"                                        \
         "Enter your option: ");
  scanf(" %c", &option);
  clear_input_stream();

  switch(option) {
    case 'a':
      qsort(inventory, num_parts, sizeof(struct part), comp_parts_by_number);
      break;
    case 'b':
      qsort(inventory, num_parts, sizeof(struct part), comp_parts_by_name);
      break;
    case 'c':
      qsort(inventory, num_parts, sizeof(struct part), comp_parts_by_on_hand);
      break;
    default:
      fprintf(stderr, "[ERROR] Invalid Command Entered.\n");
  }
}

void update (void) {
  int i, number, change;
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

  i = find_part(number);

  if (i >= 0) {
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
    inventory[i].on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print (void) {
  int i;

  printf("Part Number   Part Name                 "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++) {
    printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
  }
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

int comp_parts_by_number (const void *p, const void *q) {
  if (((struct part *) p)->number > ((struct part *) q)->number) {
    return 1;
  } else if (((struct part *) p)->number < ((struct part *) q)->number) {
    return -1;
  } else {
    return 0;
  }
}

int my_strcmp (const char *s, const char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

int comp_parts_by_name (const void *p, const void *q) {
  return my_strcmp(((struct part *) p)->name, ((struct part *) q)->name);
}

int comp_parts_by_on_hand (const void *p, const void *q) {
  if (((struct part *) p)->on_hand < ((struct part *) q)->on_hand) {
    return 1;
  } else if (((struct part *) p)->on_hand > ((struct part *) q)->on_hand) {
    return -1;
  } else {
    return 0;
  }
}

