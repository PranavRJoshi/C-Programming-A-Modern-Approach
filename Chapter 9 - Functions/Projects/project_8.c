// Q. Write a program that simulates the game of craps, which is played with two dice. On the first roll, the player wins if the sum of the dice is 7 or 11. The player loses if the sum is 2, 3, or 12. Any other roll is called the "point" and the game continues. On each subsequent roll, the player wins if he or she rolls the point again. The player loses by rolling 7. Any other roll is ignored and the game continues. At the end of each game, the program will ask the user whether or not to play again. When the user enters a response other than y or Y, the program will display the number of wins and losses and then terminate.
//    You rolled: 8
//    Your point is 8
//    You rolled: 3
//    You rolled: 10
//    You rolled: 8
//    You win!
//
//    Play again? y
//
//    You rolled: 6
//    Your point is 6
//    You rolled: 5
//    You rolled: 12
//    You rolled: 3
//    You rolled: 7
//    You lose!
//
//    Play again? y
//
//    You rolled: 11
//    You win!
//
//    Play again? n
//
//    Wins: 2   Losses: 1
// Write your program as three functions: main, roll_dice, and play_game. Here are the prototypes for the latter two functions:
//    int roll_dice (void);
//    bool play_game (void);
// roll_dice should generate two random numbers, each between 1 and 6, and return their sum. play_game should play one craps game (calling roll_dice to determine the outcome of each dice roll); it will return true if the player wins and false if the player loses. play_game is also responsible for displaying messages showing the results of the player's dice rolls. main will call play_game repeatedly, keeping track of the number of wins and losses and displaying "you win" and "you lose" messages. Hinet: Use the rand function to generate random numbers. See the deal.c program in Section 8.2 for an example of how to call rand and the related srand function.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice (void);
bool play_game (void);

int main (void) {

  int wins_count = 0;
  int losses_count = 0;

  bool is_playing = true;
  bool is_game_over = false;

  char play_option;

  srand((unsigned int) time(NULL));

  // is_game_over keeps track of the user input, if they want to play or not
  while (!is_game_over) {
    // is_playing stores the result of game, that is won or lost based on the given condition
    // and winning count or losing count is incremented accordingly
    is_playing = play_game();
    if (is_playing) {
      wins_count++;
    } else {
      losses_count++;
    }

    // asks the user if they want to play again
    printf("\nPlay again? ");
    // stores the user character
    play_option = getchar();

    if (play_option == 'y' || play_option == 'Y') {
      is_game_over = false;
    } else {
      is_game_over = true;
    }
    // this getchar is used to take in the '\n' or "return" or "enter" character the uses presses after the y or any other character
    // to either continue or end the game.
    getchar();
  }

  printf("Wins: %d  Losses: %d\n", wins_count, losses_count);
  
  return 0;
}

int roll_dice (void) {

  // defining srand inside this function is fruitless
  // if we want to generate a new batch of pseudo-random number from rand, we should only use srand once
  // as the man page states:
  // "These sequences are repeatable by calling srand() with the same seed value."
  // and since we define srand as: srand((unsigned int) time(NULL))
  // time(NULL) returns, as described in the man page:
  // "On success, the value of time in seconds since the Epoch is returned."
  // if we were to setup srand inside the function, and since the program executes rapidly
  // the srand technically may have the same seed value when point and next_roll calls this function
  // this will result in the those variables having the same, value, hence
  // never losing unless the point has 2, 3, or 12 (losing condition)

  int dice_one = (rand() % 6) + 1;
  int dice_two = (rand() % 6) + 1;

  return dice_one + dice_two;
}

bool play_game (void) {
  int point = 0;
  int next_roll = 0;
  bool first_try = true;

  for (;;) {
    // when the first roll is done, it has to check for some given conditions as described in the question
    // hence we use the flad first_try
    // point is another variable we use to keep track of the first value we got that is neither winning or losing value.
    if (first_try) {
      point = roll_dice();
      if (point == 7 || point == 11) {
        printf("You rolled: %d\n", point);
        printf("You win!\n");
        return true;
      } else if (point == 2 || point == 3 || point == 12) {
        printf("You rolled: %d\n", point);
        printf("You lose!\n");
        return false;
      } else {
        // if the winning or losing condition is not met
        // reset the first_try flag and start using the else clause
        printf("You rolled: %d\n", point);
        printf("Your point is: %d\n", point);
        first_try = false;
      }
    } else {
      // next_roll stores the second and the rest of the rolls
      next_roll = roll_dice();
      printf("You rolled: %d\n", next_roll);
      if (next_roll == point) {
        printf("You win!\n");
        return true;
      } else if (next_roll == 7) {
        printf("You lose!\n");
        return false;
      }
    }
  }
}
