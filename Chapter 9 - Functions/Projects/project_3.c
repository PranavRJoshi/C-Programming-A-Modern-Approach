// Q. Modify Programming Project 9 from Chapter 8 so that it includes the following functions:
//    void generate_random_walk (char walk[10][10]);
//    void print_array (char walk[10][10]);
// main first calls generate_random_walk, which initializes the array to contain '.' characters and then replaces some of these characters by the letters A through Z, as described in the original project, main then calls print_array to display the array on the screen.

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void generate_random_walk (int row, int col, char walk[row][col]);
void print_array (int row, int col, char walk[row][col]);

int main (void) {

  int row, col;

  // lowest value for which this program computes as required
  row = col = 2;

  printf("This program builds a random walk.\n");
  
  printf("Enter the row of the matrix: ");
  scanf("%d", &row);

  printf("Enter the column of the matrix: ");
  scanf("%d", &col);
  
  // using a Variable Length Array (VLA) (for practice mostly)
  char walk[row][col];

  // this function essentially initializes the array
  // and also generates the random walk which was done in the Programming Project 9 of Chapter 8
  // Most of the code is explained in that file, and is removed here to not make a mess with comments
  // some of the thing changed here is the edge cases condition
  // where the previous program had an array of lenth 10 x 10
  // but since this program utilizes VLA 
  // we have to change the condition from using 9, to, say, (col_size - 1)
  generate_random_walk(row, col, walk);

  print_array(row, col, walk);

  return 0;
}

void generate_random_walk (int r, int c, char w[r][c]) {

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      w[i][j] = '.';
    }
  }

  // initial direction for the character to be added
  int horizontal_direction = 0;
  int vertical_direction = 0;
  // store the random number
  int next_direction;
  // store the alphabet
  char ch = 'A';
  // keep track if there are no nearby walk to go
  bool is_blocked = false;

  // initialize the seed for rand funtion
  srand((unsigned int) time(NULL));

  while (ch <= 'Z') {

    w[horizontal_direction][vertical_direction] = ch;

    if (is_blocked) {
      break;
    } else {
        ch = ch + 1;
    }
    
    while (1) {
      next_direction = rand() % 4;

      // go up
      if (next_direction == 0) {
        horizontal_direction -= 1;
        if (horizontal_direction < 0) {
          horizontal_direction += 1;
          continue;
        }
      }
      
      // go right
      if (next_direction == 1) {
        vertical_direction += 1;
        if (vertical_direction > (c -1)) {
          vertical_direction -= 1;
          continue;
        }
      }
      
      // go down
      if (next_direction == 2) {
        horizontal_direction += 1;
        if (horizontal_direction > (r - 1)) {
          horizontal_direction -= 1;
          continue;
        }
      }

      // go left
      if (next_direction == 3) {
        vertical_direction -= 1;
        if (vertical_direction < 0) {
          vertical_direction += 1;
          continue;
        }
      }

      // if the upcomming path already has a alphabet assigned to it
      // go to the previous pointed path and retry
      if (w[horizontal_direction][vertical_direction] != '.') {
        if (next_direction == 0) {
          horizontal_direction += 1;
        } else if (next_direction == 1) {
          vertical_direction -= 1;
        } else if (next_direction == 2) {
          horizontal_direction -= 1;
        } else if (next_direction == 3) {
          vertical_direction += 1;
        }
        continue;
      }

      // covers the edge cases for the top edge, including the top corners
      if (horizontal_direction == 0) { 
        if (vertical_direction == 0) {
          if (w[horizontal_direction+1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction+1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction == (c - 1)) {
          if (w[horizontal_direction+1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction-1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction > 0 && vertical_direction < (c - 1)) {
          if (w[horizontal_direction][vertical_direction+1] != '.' && w[horizontal_direction][vertical_direction-1] != '.' && w[horizontal_direction+1][vertical_direction] != '.') {
            is_blocked = true;
            break;
          }
        }
      } else if (horizontal_direction == (r - 1)) {
        // covers the edge cases for the bottom edge, including the bottom corners
        if (vertical_direction == 0) {
          if (w[horizontal_direction-1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction+1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction == (c - 1)) {
          if (w[horizontal_direction-1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction-1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction > 0 && vertical_direction < (c - 1)) {
          if (w[horizontal_direction][vertical_direction+1] != '.' && w[horizontal_direction][vertical_direction-1] != '.' && w[horizontal_direction-1][vertical_direction] != '.') {
            is_blocked = true;
            break;
          }
        }
      }

      // covers the edge case for the left edge
      if (vertical_direction == 0 && (horizontal_direction > 0 && horizontal_direction < (r - 1))) {
        if (w[horizontal_direction+1][vertical_direction] != '.' && w[horizontal_direction-1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction+1] != '.') {
          is_blocked = true;
          break;
        }
      }

      // covers the edge case for the right edge 
      if (vertical_direction == 9 && (horizontal_direction > 0 && horizontal_direction < (r - 1))) {
        if (w[horizontal_direction+1][vertical_direction] != '.' && w[horizontal_direction-1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction-1] != '.') {
          is_blocked = true;
          break;
        }
      }
      
      // covers the cases for when the upcoming position inside the matrix
      if (w[horizontal_direction+1][vertical_direction] != '.' && w[horizontal_direction-1][vertical_direction] != '.' && w[horizontal_direction][vertical_direction+1] != '.' && w[horizontal_direction][vertical_direction-1] != '.') {
        is_blocked = true;
        break;
      }
      break;
    }
  }
}

void print_array (int r, int c, char w[r][c]) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%c ", w[i][j]);
    }
    printf("\n");
  }
}

