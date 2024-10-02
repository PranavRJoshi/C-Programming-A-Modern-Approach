// Q. Write a program that generates a "random-walk" across 10 x 10 array. The array will contain characters (all '.' initially). The program must randomly "walk" from element to element, always going up, down, left, or right by one element. The elements visited by the program will be labeled with the letters 'A' through 'Z', in the order visited. Here's an example of the desired output:
//    A . . . . . . . . .
//    B C D . . . . . . .
//    . F E . . . . . . .
//    H G . . . . . . . . 
//    I . . . . . . . . . 
//    J . . . . . . . Z .
//    K . . R S T U V Y .
//    . N O . . . . . . .
//    . . . . . . . . . .
// Hint: Use the srand and rand functions (see deal.c) to generate random numbers. After generating a number, look at its remainder when divided by 4. There are four possible values for the remainder--0, 1, 2, and 3--indicating the direction of the next move. Before performing a move, check that (a) it won't go outside the array, and (b) it doesn't take us to an element that already has a letter assigned. If either condition is violated, try moving in another direction. If all four directions are blocked, the program must terminate. Here's an example of premature termination:
//    A B G H I . . . . .
//    . C F . J K . . . .
//    . D E . M L . . . .
//    . . . . N O . . . . 
//    . . W X Y P Q . . .
//    . . V U T S R . . .
//    . . . . . . . . . .
//    . . . . . . . . . .
//    . . . . . . . . . .
//    . . . . . . . . . .
// Y is blocked on all four sides, so there's no place to put Z.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int main (void) {

  // char walking_path[10][10] = {{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  //                              {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
  // or we can initialize the variable walking_path as:
  char walking_path[ROW_SIZE][COL_SIZE];
  for (int i = 0; i < ROW_SIZE; i++) {
    for (int j = 0; j < COL_SIZE; j++) {
      walking_path[i][j] = '.';
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

    walking_path[horizontal_direction][vertical_direction] = ch;

    // when the loop iterates, check if the flag is_blocked is true or false.
    if (is_blocked) {
      break;
    } else {
        ch = ch + 1;
    }
    
    // this while loop iterates till we find a direction that does not go out of bound of the walking path
    // also this loop will check if the next_direction that was generated has any issue like
    // we check for edge cases when the adjacent path from the next_direction are already filled or not
    // if those paths are filled, the is_blocked flag will be set and break from the loop
    // also, when the next_direction generated already has a alphabet in that space, it will reset the direction and continue to loop till we find the next_direction that has '.'
    while (1) {
      // generate a random number
      next_direction = rand() % 4;

      // if the value is 0, go up
      if (next_direction == 0) {
        horizontal_direction -= 1;
        // the negative value of horizontal direction indicates that the array is on the top and is going out of bound
        if (horizontal_direction < 0) {
          horizontal_direction += 1;
          continue;
        }
      }

      // if the value is 1, go right
      if (next_direction == 1) {
        vertical_direction += 1;
        // the value of vertical direction being greater than 9 indicates the array is on far right and is going out of bound
        if (vertical_direction > 9) {
          vertical_direction -= 1;
          continue;
        }
      }
      
      // if the value is 2, go down
      if (next_direction == 2) {
        horizontal_direction += 1;
        // the value of horizontal direction being greater than 9 indicates the array is far down and is going out of bound
        if (horizontal_direction > 9) {
          horizontal_direction -= 1;
          continue;
        }
      }

      // if the value is 3, go left
      if (next_direction == 3) {
        vertical_direction -= 1;
        // the negative value of vertical direction indicates that the array is on the left and is going out of bound
        if (vertical_direction < 0) {
          vertical_direction += 1;
          continue;
        }
      }

      // check if the direction chosen already has alphabetic character added or not
      // if there already exists a character, we restore the direction and loop again
      if (walking_path[horizontal_direction][vertical_direction] != '.') {
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

      // This is a massive conditional statement that checks for edge cases (hd = horizontal_direction, vd = vertical_direction)
      // The if statement below checks the condition when the current path has horizontal direction 0, i.e. on the top
      // i.e. in the top-left corner (hd = 0, vd = 0), top-right corner (hd = 0, vd = 9), and the top edge (hd = 0, vd > 0 and vd < 9) in respective order of the if branching done 
      if (horizontal_direction == 0) { 
        if (vertical_direction == 0) {
          // [corner] check if the bottom path and right path are already filled
          if (walking_path[horizontal_direction+1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction+1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction == 9) {
          // [corner] check if the bottom path and left path are already filled
          if (walking_path[horizontal_direction+1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction-1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction > 0 && vertical_direction < 9) {
          // [edge] check if the right path, the left path and the bottom path are already filled
          if (walking_path[horizontal_direction][vertical_direction+1] != '.' && walking_path[horizontal_direction][vertical_direction-1] != '.' && walking_path[horizontal_direction+1][vertical_direction] != '.') {
            is_blocked = true;
            break;
          }
        }
      } else if (horizontal_direction == 9) {
        // this else-if is for the case when the path is on the bottom
        if (vertical_direction == 0) {
          // [corner] check if the above path and the right path are already filled 
          if (walking_path[horizontal_direction-1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction+1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction == 9) {
          // [corner] check if the above path and the left path are already filled
          if (walking_path[horizontal_direction-1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction-1] != '.') {
            is_blocked = true;
            break;
          }
        } else if (vertical_direction > 0 && vertical_direction < 9) {
          // [edge] check if the right path, the left path and the above path are already filled 
          if (walking_path[horizontal_direction][vertical_direction+1] != '.' && walking_path[horizontal_direction][vertical_direction-1] != '.' && walking_path[horizontal_direction-1][vertical_direction] != '.') {
            is_blocked = true;
            break;
          }
        }
      }

      // this checks for the condition when the current path is on the left edge and checks if the three adjacent sides are avaiable or not, if not, then it will terminate
      if (vertical_direction == 0 && (horizontal_direction > 0 && horizontal_direction < 9)) {
        // [edge] check if the below path, the above path, and the right path are already filled
        if (walking_path[horizontal_direction+1][vertical_direction] != '.' && walking_path[horizontal_direction-1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction+1] != '.') {
          is_blocked = true;
          break;
        }
      }

      // this checks for the condition when the current path is on the right edge and checks if the three adjacent sides are avaiable or not, if not, then it will terminate
      if (vertical_direction == 9 && (horizontal_direction > 0 && horizontal_direction < 9)) {
        // [edge] check if the below path, the left path and the right path are already filled or not
        if (walking_path[horizontal_direction+1][vertical_direction] != '.' && walking_path[horizontal_direction-1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction-1] != '.') {
          is_blocked = true;
          break;
        }
      }
      
      // [inner square] check if the below path, the above path, the right path, and the left path are already filled
      if (walking_path[horizontal_direction+1][vertical_direction] != '.' && walking_path[horizontal_direction-1][vertical_direction] != '.' && walking_path[horizontal_direction][vertical_direction+1] != '.' && walking_path[horizontal_direction][vertical_direction-1] != '.') {
        is_blocked = true;
        break;
      }
      
      // if any of the edge cases are true, the is_blocked flag turns true, and the terminates from the inner while loop
      // and when it re-iterates the outer while loop, the is_blocked set flag terminates from that loop too
      // if non of the edge cases are met, we can assure that the next_direction picked has no issue
      // and the program runs as intended.

      break;
    }
  }

  // prints the newly generated "random-walk" path
  printf("The randomly generated walk is: \n");

  for (int i = 0; i < ROW_SIZE; i++) {
    for (int j = 0; j < COL_SIZE; j++) {
      printf("%c ", walking_path[i][j]);
    }
    printf("\n");
  }

  return 0;
}

