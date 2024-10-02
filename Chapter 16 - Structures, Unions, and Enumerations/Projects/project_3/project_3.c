// Q. Modify the inventory.c program of Section 16.3 by making inventory and num_parts local to the main function.

#include <stdio.h>
#include <stdbool.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

/*
 * find_part: Looks up part number in the inventory
 *            array. Returns the array index if the part
 *            number is found; otherwise, returns -1
*/
int find_part(struct part *inventory, int num_parts, int number);

/*
 * insert:  Prompts the user for information about a new part
 *          and then inserts the part into the database. Prints
 *          an error message and returns false if the part
 *          already exists or the database is full. On successful
 *          insertion, returns true.
*/
bool insert (struct part *inventory, int num_parts);

/*
 * search:  Prompts the user to enter a part number, then
 *          looks up the part in the database. If the part
 *          exists, prints the name and quantity on hand;
 *          if not, prints an error message
*/
void search (struct part *inventory, int num_parts);

/*
 * update:  Prompts the user to enter a part number.
 *          Prints an error message if the part doesn't 
 *          exist; otherwise, prompts the user to enter
 *          change in quantity on hand and updates the
 *          database
*/
void update (struct part *inventory, int num_parts);

/*
 * print: Prints a listing of all parts in the database,
 *        showing the part number, part name, and 
 *        quantity on hand. Parts are printed in the 
 *        order in which they were entered into the 
 *        database
*/
void print (struct part *inventory, int num_parts);

/*
 * clear_input_stream:  Clears the input stream, if it contains any characters
 *                      that was left behind, specifically by scanf.
*/
void clear_input_stream (void);

/*
 * main:  Prompts the user to enter an operation code, 
 *        then calls a function to perform the requested
 *        action. Repeats until the user enters the command
 *        'q'. Prints an error message if the user enters an 
 *        illegal code.
*/
int main (void) {
  char code;

  struct part inventory[MAX_PARTS];
  int num_parts = 0;    /* number of parts currently stored. */


  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    
    clear_input_stream();

    switch (code) {
      case 'i':
        if (insert(inventory, num_parts)) {
          num_parts++;
        }
        break;
      case 's':
        search(inventory, num_parts);
        break;
      case 'u':
        update(inventory, num_parts);
        break;
      case 'p':
        print(inventory, num_parts);
        break;
      case 'q':
        return 0;
      default:
        printf("Illegal Code.\n");
    }
    printf("\n");
  }

  return 0;
}

int find_part (struct part *inventory, int num_parts, int number) {
  int i;

  for (i = 0; i < num_parts; i++) {
    if (inventory[i].number == number) {
      return i;
    }
  }

  return -1;
}

bool insert (struct part *inventory, int num_parts) {
  int part_number;

  int scanf_return_count = 0;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return false;
  }

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &part_number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    if (part_number < 0) {
      fprintf(stderr, "[WARN] The part number cannot be negative.\n");
      clear_input_stream();
      continue;
    }
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }

  if (find_part(inventory, num_parts, part_number) >= 0) {
    printf("Part already exists.\n");
    return false;
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
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }
  return true;
}

void search (struct part *inventory, int num_parts) {
  int i, number;
  int scanf_return_count = 0;

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }

  i = find_part(inventory, num_parts, number);

  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void update (struct part *inventory, int num_parts) {
  int i, number, change;
  int scanf_return_count = 0;

  for (;;) {
    printf("Enter part number: ");
    if ((scanf_return_count = scanf("%d", &number)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }

  i = find_part(inventory, num_parts, number);

  if (i >= 0) {
    for (;;) {
      printf("Enter change in quantity on hand: ");
      if ((scanf_return_count = scanf("%d", &change)) != 1) {
        fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
        clear_input_stream();
        continue;
      }
      clear_input_stream();
      scanf_return_count = 0;
      break;
    }
    inventory[i].on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print (struct part *inventory, int num_parts) {
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

