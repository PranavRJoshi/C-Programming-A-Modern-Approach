// Q. The program is built around an array of structures, with each structure containing information--part number, name, and quantity--about one part. Our program will support the following operations:
//    1. Add a new part number, part name, and initial quantity on hand: The program must print an error message if the part is already in the database or if the database is full. 
//    2. Given a part number, print the name of the part and the current quantity on hand: The program must print an error message if the part number isn't in the database.
//    3. Given a part number, change the quantity on hand: The program must print an error message if the part number isn't in the database.
//    4. Print a table showing all information in the database: Parts must be displayed in the order in which they were entered.
//    5. Terminate program execution.
// We'll use the codes i (insert), s (search), u (update), p (print), and q (quit) to represent these operations. A session with the program might look like this:
//    Enter operation code: i 
//    Enter part number: 528 
//    Enter part name: Disk drive
//    Enter quantity on hand: 10
//
//    Enter operation code: s 
//    Enter part number: 528 
//    Part name: Disk drive 
//    Quantity on hand: 10 
//
//    Enter operation code: s 
//    Enter part number: 914 
//    Part not found.
//
//    Enter operation code: i 
//    Enter part number: 914
//    Enter part name: Printer cable 
//    Enter quantity on hand: 5 
//
//    Enter operation code: u 
//    Enter part number: 528 
//    Enter change in quantity on hand: -2 
//
//    Enter operation code: s 
//    Enter part number: 528 
//    Part name: Disk drive 
//    Quantity on hand: 8 
//
//    Enter operation code: p 
//    Part Number         Part Name             Quantity on Hand 
//        528             Disk drive                    8
//        914             Printer Cable                 5 
//
//    Enter operation code: q 
//
// The program will store information about each part in a structure. We'll limit the size of the database to 100 parts, making it possible to store the structures in an array, which I'll call inventory. (If this limit proves to be too small, we can always change it later.) To keep track of the number of parts currently stored in the array, we'll use a variable named num_parts. 
// Since this program is menu-driven, it's fairly easy to sketch the main loop: 
//    for (;;) {
//      prompt user to enter operation code;
//      read_code;
//      switch (code) {
//        case 'i': perform insert operation; break;
//        case 's': perform search operation; break;
//        case 'u': perform update operation; break;
//        case 'p': perfrom print operation; break;
//        case 'q': terminate program;
//        default: print error message;
//      }
//    }
// It will be convenient to have a separate functions perform the insert, search, update, and print operations. Since these functions will all need access to inventory and num_parts, we might want to make these variables external. As an alternative, we could declare the variables inside main, and then pass them to the functions as arguments. From a design standpoint, it's usually better to make variables local to a function rather than making them external (see Section 10.2 if you've forgotten why). In this program, however, putting inventory and num_parts inside main would merely complicate matters. 
//
// For reasons that I'll explain later, I've decided to split the program into three files: inventory.c, which contains the bulk of the program; readline.h, which contains the prototype for the read_line function; and readline.c, which contains the definition for the read_line. We'll discuss the latter two files later in this section. For now, let's concentrate on inventory.c. 

/* Maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;    /* number of parts currently stored. */

int find_part(int number);
void insert (void);
void search (void);
void update (void);
void print (void);

/*
 * main:  Prompts the user to enter an operation code, 
 *        then calls a function to perform the requested
 *        action. Repeats until the user enters the command
 *        'q'. Prints an error message if the user enters an 
 *        illegal code.
*/
int main () {
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    
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
        printf("Illegal Code.\n");
    }
    printf("\n");
  }
}

/*
 * find_part: Looks up part number in the inventory
 *            array. Returns the array index if the part
 *            number is found; otherwise, returns -1
*/
int find_part (int number) {
  int i;

  for (i = 0; i < num_parts; i++) {
    if (inventory[i].number == number) {
      return i;
    }
  }

  return -1;
}

/*
 * insert:  Prompts the user for information about a new part
 *          and then inserts the part into the database. Prints
 *          an error message and returns prematurely if the part
 *          already exists or the database is full.
*/
void insert (void) {
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

/*
 * search:  Prompts the user to enter a part number, then
 *          looks up the part in the database. If the part
 *          exists, prints the name and quantity on hand;
 *          if not, prints an error message
*/
void search (void) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);

  i = find_part(number);

  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else {
    printf("Part not found.\n");
  }
}

/*
 * update:  Prompts the user to enter a part number.
 *          Prints an error message if the part doesn't 
 *          exist; otherwise, prompts the user to enter
 *          change in quantity on hand and updates the
 *          database
*/
void update (void) {
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);

  i = find_part(number);

  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else {
    printf("Part not found.\n");
  }
}

/*
 * print: Prints a listing of all parts in the database,
 *        showing the part number, part name, and 
 *        quantity on hand. Parts are printed in the 
 *        order in which they were entered into the 
 *        database
*/
void print (void) {
  int i;

  printf("Part Number   Part Name                 "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++) {
    printf("%7d       %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
  }
}

// In the main function, the format string " %c" allows scanf to skip over white space before reading the operation code. The space in the format string is crucial; without it, scanf would sometimes read the new-line character that terminated a previous line of input.
// The program contains one function, find_part, that isn't called from main. This "helper" function helps us avoid redundant code and simplify the more important functions. By calling find_part, the insert, search, and update functions can locate a part in the database (or simply determine if the part exists).
// There's just one detail left: the read_line function, which the program uses to read the part name. Section 13.3 discussed the issues that are involved in writing such a function. Unfortunately, the version of read_line in that section won't work properly in the current program. Consider what happens when the user inserts a part: 
//    Enter part number: 528
//    Enter part name: Disk drive
// The user presses the Enter key after entering the part number and again after entering the part name, each time leaving an invisible new-line character that the program must read. For the sake of discussion, let's pretend that these characters are visible (denoted by * for now):
//    Enter part number: 528*
//    Enter part name: Disk drive*
// When we call scanf to read the part number, it consumes the 5, 2, and 8, but leaves the * character unread. If we try to read the part name using our original read_line function, it will encounter the * character immediately and stops reading. This problem is common when numerical input is followed by character input. Our solution will be to write a version of read_line that skips white-space characters before it begins storing characters. Not only, will this solve the new-line problem, but it also allows us to avoid storing any banks that precede the part name.
