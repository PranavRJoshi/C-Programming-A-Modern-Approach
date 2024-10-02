// Q. Our next program illustrates both two-dimensional arrays and constant arrays. The program deals a random hand from a standard deck of playing cards. (In case you haven't had time to play games recently, each card in a standard deck has a suit--clubs, diamond, heats, or spades--and a rank--two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, or ace.) We'll have the user specify how many cards should be in the hand:
//    Enter number of cards in hand: 5
//    Your hand: 7c 2s 5d as 2h
// It's not immediately obvious how we'd write such a program. How do we pick cards randomly from the deck? And how do we avoid picking the same cards randomly from the deck? And how do we avoid picking the same card twice? Let's tackle these problems separately. 
// To pick cards randomly, we'll use several C library functions. The time function (from <time.h>) returns the current time, encoded in a single number. The srand function (from <stdlib.h>) initializes C's random number generator. Passing the return value of time to srand prevents the program from dealing the same cards every time we run it. The rand function (also from <stdlib.h>) produces an apparently random number each time it's called. By using the % operator, we can scale the return value from srand so that it falls between 0 and 3 (for suits) or between 0 and 12 (for ranks).
// To avoid picking the same card twice, we'll need to keep track of which cards have already been chosen. For that purpose, we'll use an array named in_hand that has four rows (one for each suit) and 13 columns (one for each rank). In other words, each element in the array corresponds to one of the 52 cards in the deck. All elements of the array will be false to start with. Each time we pick a card at random, we'll check whether the element of in_hand corresponding to that card is true or false. If it's true, we'll have to pick another card. If it's false, we'll store true in that card's array element to remind us later that this card has already been picked.
// Once we've verified that a card is "new"--not already selected--we'll need to translate its numerical rank and suit into characters and then display the card. To translate the rank and suit to character form, we'll set up two arrays of characters--one for the rank and one for the suit--and then use the numbers to subscript the arrays. These arrays won't change during program execution, so we may as well declare them to be const.

// Some notes on the functions we'll use in the following program
// time_t time(time_t *second) - where the value of time_t is long (using typedef long -> __darwin_time_t -> time_t). Returns the value of type time_t (long). If the argument is given for the function, stores the time in the memory pointed to by second. The function is nullable, i.e. NULL can be passed as an argument.
// int rand(void) - returns a pseudo-random integer in the range 0 to RAND_MAX (0x7fffffff -> 2147483647) inclusive (the RAND_MAX is the maximum allowable integer that can be stored in the int type). The rand function does not take any argument.  
// void srand(unsigned) - sets its argument "seed" as the seed for a new sequence of pseudo-random numbers to be returned by rand(). These sequence are repeatable by calling srand() with the same seed value. If no seed value if provided, the functions are automatically seeded with a value of 1.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
  const char rank[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'j', 'q', 'k', 'a'};
  const char suit[] = {'c', 'd', 'h', 's'};

  printf("Your hand: ");

  // using for loop can be hard, if in_hand is true, then we need to discard the current iteration
  // and since the number of cards remains as is, there is no other way to modify the second expression such that it accounts for duplicate card in hand. The following example below was displayed when for loop was made
  // for (int i = 0; i < number_of_cards; i++) { if (...) {...} else { i--; continue } }
  // Enter number of cards in hand: 5
  // Your hand: kc 8h 7c ch cs
  while (number_of_cards > 0) {
    // store the random value by calling the rand function
    random_rank = rand() % NUM_RANKS;
    random_suit = rand() % NUM_SUITS;
    // printf("The random rank and suit are: %d and %d\n", random_rank, random_suit); 
    if (in_hand[random_suit][random_rank] == false) {
      in_hand[random_suit][random_rank] = true;
      printf("%c%c ", rank[random_rank], suit[random_suit]);
      number_of_cards--;
    } 
  }

  printf("\n");

  return 0;  
}

