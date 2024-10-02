// Q. Modify the deal.c program of Section 8.2 so that it prints the full names of the cards it deals:
//    Enter number of cards in hand: 5
//    Your hand:
//    Seven of clubs
//    Two of spades
//    Five of diamonds
//    Ace of spades
//    Two of hearts
// Hint: Replace rank_code and suit_code by arrays containing pointers to strings.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define NUM_RANKS 13
#define NUM_SUITS 4

int main (void) {

  // 
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int number_of_cards;
  int random_rank, random_suit;

  // initialize pseudo-random sequence
  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &number_of_cards);

  // these constant character array hold the ranks and suits of the deck
  const char *named_rank[] = {"Two",
                             "Three",
                             "Four",
                             "Five",
                             "Six",
                             "Seven",
                             "Eight",
                             "Nine",
                             "Ten",
                             "Jack",
                             "Queen",
                             "King",
                             "Ace"};

  const char *named_suit[] = {"Clubs",
                             "Diamonds",
                             "Hearts",
                             "Spades"};

  printf("Your hand:\n");

  while (number_of_cards > 0) {
    random_rank = rand() % NUM_RANKS;
    random_suit = rand() % NUM_SUITS;
    if (in_hand[random_suit][random_rank] == false) {
      in_hand[random_suit][random_rank] = true;
      printf("%10s of %-10s\n", *(named_rank + random_rank), *(named_suit + random_suit));
      number_of_cards--;
    } 
  }

  printf("\n");

  return 0;  
}


