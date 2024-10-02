// Q. Modify the inventory.c program of Section 16.3 so that the inventory array is allocated dynamically and later reallocated when it fills up. Use malloc initially to allocate enough space for an array of 10 part structures. When the array has no more room for new parts, use realloc to double its size. Repeat the doubling step each time the array becomes full.

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} *inventory;

int curr_total_max_parts = 2;
int num_parts = 0;    /* number of parts currently stored. */

int find_part(int number);
void insert (void);
void search (void);
void update (void);
void print (void);

int main () {
  char code;

  inventory = malloc(sizeof(struct part) * curr_total_max_parts);
  if (inventory == NULL) {
    fprintf(stderr, "[ERROR] Failed to allocate enough memory. Exiting.\n");
    exit(EXIT_FAILURE);
  }

  for (;;) {
    printf("A Program to Store Information About Parts. Parts Contains The Members:\n"                  \
           "Member 1: number  (int)\n"                                                                  \
           "Member 2: name    (char[25])\n"                                                             \
           "Member 3: on_hand (int)\n"                                                                  \
           "Usage                   Command\n"                                                          \
           "-----                   -------\n"                                                          \
           "1. Insert Item            (i)\n"                                                            \
           "2. Search Item            (s)\n"                                                            \
           "3. Update Item            (u)\n"                                                            \
           "4. Print Items            (p)\n"                                                            \
           "5. Quit Program           (q)\n"                                                            \
           "parts command >> ");
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
      case 'q':
        free(inventory);
        inventory = NULL;
        exit(EXIT_SUCCESS);
      default:
        printf("Illegal Code.\n");
    }
    printf("\n");
  }
}

int find_part (int number) {
  int i;

  for (i = 0; i < num_parts; i++) {
    if ((inventory + i)->number == number) {
      return i;
    }
  }

  return -1;
}

void insert (void) {
  int part_number;

  if (num_parts == curr_total_max_parts) {
    printf("Database is full. Doubling the size...\n");
    curr_total_max_parts *= 2;
    inventory = realloc(inventory, sizeof(struct part) * curr_total_max_parts);

    if (inventory == NULL) {
      fprintf(stderr, "[FATAL ERROR] Failed to Allocate Enough Memory. Exiting.\n");
      exit(EXIT_FAILURE);
    }
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  clear_input_stream();

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  (inventory + num_parts)->number = part_number;
  printf("Enter part name: ");
  read_line((inventory + num_parts)->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &((inventory + num_parts)->on_hand));
  clear_input_stream();
  num_parts++;
}

void search (void) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);

  i = find_part(number);

  if (i >= 0) {
    printf("Part name: %s\n", (inventory + i)->name);
    printf("Quantity on hand: %d\n", (inventory + i)->on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void update (void) {
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);

  i = find_part(number);

  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    (inventory + i)->on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

void print (void) {
  int i;

  printf("Part Number   Part Name                 "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++) {
    printf("%7d       %-25s%11d\n", (inventory + i)->number, (inventory + i)->name, (inventory + i)->on_hand);
  }
}

