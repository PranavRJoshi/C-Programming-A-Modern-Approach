// Q. Modify the inventory.c program of Section 16.3 by adding a price member to the part structure. The insert function should ask the user for the price of a new item. The search and print functions should display the price. Add a new command that allows the user to change the price of a part.

#include <stdio.h>
#include <stdbool.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  double price;
} inventory[MAX_PARTS];

int num_parts = 0;    /* number of parts currently stored. */

/*
 * find_part: Looks up part number in the inventory
 *            array. Returns the array index if the part
 *            number is found; otherwise, returns -1
*/
int find_part(int number);

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
 * print: Prints a listing of all parts in the database,
 *        showing the part number, part name, and 
 *        quantity on hand. Parts are printed in the 
 *        order in which they were entered into the 
 *        database
*/
void print (void);

/*
 * update_price:  Updates the price for the given part number.
 *                If invalid part number is provided, displays an error.
*/
void update_price (void);

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

  for (;;) {
    printf("    Usage                     Command\n"                \
           "1. Insert new part              (i)\n"                  \
           "2. Search part                  (s)\n"                  \
           "3. Update on_hand quantity      (u)\n"                  \
           "4. Print the parts              (p)\n"                  \
           "5. Update part's price          (h)\n"                  \
           "6. Quit the program             (q)\n"                  \
           "Enter operation code: ");
    scanf(" %c", &code);

    clear_input_stream();
    
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
      case 'h':
        update_price();
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
    if (part_number < 0) {
      fprintf(stderr, "[WARN] The part number cannot be negative.\n");
      clear_input_stream();
      continue;
    }
    clear_input_stream();
    scanf_return_count = 0;
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
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }
  for (;;) {
    printf("Enter the price of the part: ");
    if ((scanf_return_count = scanf("%lf", &inventory[num_parts].price)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    clear_input_stream();
    scanf_return_count = 0;
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
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }

  i = find_part(number);

  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
    printf("Price: %g\n", inventory[i].price);
  } else {
    printf("Part not found.\n");
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
    clear_input_stream();
    scanf_return_count = 0;
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
      clear_input_stream();
      scanf_return_count = 0;
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
         "Quantity on Hand    Price\n");
  for (i = 0; i < num_parts; i++) {
    printf("%7d       %-25s%11d       %10g\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
  }
}

void update_price (void) {
  int i, number;
  int scanf_return_count = 0;
  double new_price;

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

  i = find_part(number);

  if (i >= 0) {
    for (;;) {
      printf("Enter the new price for the part: ");
      if ((scanf_return_count = scanf("%lf", &new_price)) != 1) {
        fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
        clear_input_stream();
        continue;
      }
      clear_input_stream();
      scanf_return_count = 0;
      break;
    }
    inventory[i].price = new_price;
  } else {
    printf("Part not found.\n");
  }

}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}
