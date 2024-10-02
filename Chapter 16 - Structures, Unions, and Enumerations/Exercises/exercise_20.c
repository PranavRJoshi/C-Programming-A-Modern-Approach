// Q. Suppose that the direction variable is declared in the following way:
//      enum { NORTH, SOUTH, EAST, WEST } direction;
//    Let x and y be int variables. Write a switch statement that tests the value of direction, incrementing x if direction is EAST, decrementing x if direction is WEST, incrementing y if direction is SOUTH, and decrementing y if direction is NORTH.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main (void) {

  enum { NORTH, SOUTH, EAST, WEST } direction;
  int x = 0, y = 0;

  int command;

  for (;;) {
    printf("The current value of x and y is:\n"             \
           "x = %d\ny = %d\n\n", x, y);
    printf("Enter the direction as specified:\n"            \
           "    Direction               Command\n"          \
           "      North                   (n)\n"            \
           "      South                   (s)\n"            \
           "      East                    (e)\n"            \
           "      West                    (w)\n"            \
           "Enter q to exit the program.\n"                 \
           "Enter your command: ");
    while (isspace(command = getchar())) {
      ;
    }

    switch (command) {
      case 'n':
        direction = NORTH;
        break;
      case 's':
        direction = SOUTH;
        break;
      case 'e':
        direction = EAST;
        break;
      case 'w':
        direction = WEST;
        break;
      case 'q':
        exit(EXIT_SUCCESS);
      default: 
        fprintf(stderr, "[ERROR] Invalid Command Entered.\n");
    }

    while ((command = getchar()) != '\n') {
      ;
    }

    switch (direction) {
      case NORTH:
        y--;
        break;
      case SOUTH:
        y++;
        break;
      case EAST:
        x++;
        break;
      case WEST:
        x--;
        break;
      default:
        fprintf(stderr, "[ERROR] No Direction Is Specified.\n");
    }
  }

  return 0;
}
