#include <stdio.h>

#define SENTENCE_SIZE 50

int main (void) {

  char original_sentence[SENTENCE_SIZE];
  char terminating_char;
  char ch;
  int i;

  printf("Enter a sentence: ");

  // i here will be one more than needed since, zero index...
  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    if (ch == '.' || ch == '?' || ch == '!') {
      // i is not incremented when this if block is executed
      terminating_char = ch;
      break;
    }
    original_sentence[i] = ch;
  }

  printf("Reversal of sentence: ");

  // i is one more than the total word length (including space)
  // since i stores the length, but the array index starts from zero.
  // so if we have a word with 32 characters, we need to start from 31 as subscript 32 does not exist...
  i = i - 1;

  while (1) {
    // keep track of the letter count in a word
    int letter_count = 0;

    // keeps on incrementing the value of letter_count and decrements i as we backwards on the array
    // i >= 0 is required as the last word (in reverse) has no space before it, so it goes on infinite loop
    // this will cause the value of i to have -1
    while (original_sentence[i] != ' ' && i >= 0) {
      letter_count++;
      // when the character is the one before a space, this loop will still execute
      // and since i is decremented, the value of i now points to the space
      i--;
    }

    // since we are working on the same array, i.e. i, we need to increment the value
    // to go forward and reconstruct the word
    // we need to increment 1 since the value of i is one less as it accounts
    // the space that was encountered in the upper while loop
    for (int k = 0; k < letter_count; k++) {
      // we need to add 1 since the current value of i (when k = 0) will point to the space character
      printf("%c", original_sentence[i+k+1]);
    }
    
    // when we are encountering the last words in reverse, i will have the value of -1, so we need to break out of the loop
    // if we are not at the end word, then the value of i will be positive, and hence we need to add space
    if (i >= 0) {
      printf(" ");
      // i is decremented as we need to get rid of the space that is being pointed by i
      i--;
    } else {      
      break;
    }
  }

  printf("%c\n", terminating_char);

  return 0;
}

