// Q. Write a program that reverses the words in a sentence:
//    Enter a sentence: you can cage a swallow can't you?
//    Reversal of sentence: you can't swallow a cage can you?
// Hint: Use a loop to read the characters one by one and store them in a one-dimensional char array. Have the loop stop at a period, question mark, or exclamation point (the "terminating character"), which is saved in a separate char variable. Then use a second loop to search backward through the array for the beginning of the last word. Print the last word, then search backward for the next-to-last word. Repeat until the beginning of the array is reached. Finally, print the terminating character. 

// a detailed program is written on program_14a.c which explains the steps, which is similar to this program. 

#include <stdio.h>

int main (void) {

  char original_sentence[50];
  char terminating_char;
  char ch;
  int i;

  printf("Enter a sentence: ");

  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    if (ch == '.' || ch == '?' || ch == '!') {
      terminating_char = ch;
      break;
    }
    original_sentence[i] = ch;
  }

  printf("Reversal of sentence: ");

  // we use another variable, j, since if we were to manipulate the value of i inside the loop below
  // it is not mandatory to use a different variable (is illustrated in project_14a.c) but both works as intended.
  int j = i - 1;

  while (j >= 0) {
    // keep track of the letter count in a word
    int letter_count = 0;

    // while moving backward through the array, keep track of the letter_count
    // and check if the value of j is less than 0
    // the value of j is -1 when it counts the letter of the last word (in reverse, or first from original)
    // letter count is always one more than the length of the word, i.e., the letter count of "seg" is 3
    // this seems equal, but when working with arrays, we need to consider that seg is written from index 0 to 2
    while (original_sentence[i] != ' ' && j >= 0) {
      letter_count++;
      j--;
    }

    // For the reason stated above, we need to subtract 1 from the letter_count to satisfy the word length
    // since i is already one more than the total word length (including spaces), we need to subtract it while printing
    for (int k = letter_count - 1; k >= 0; k--) {
      // i stores the actual length of the characters, and it has one more than the actual length (excluding the termination character)
      // 
      printf("%c", original_sentence[i-k-1]);
    }
    
    if (j >= 0) {
      printf(" ");
      // we need to subtract 1 to point to the word that comes just before the space.
      i = i - letter_count - 1;
      j--;
    }
  }

  printf("%c\n", terminating_char);

  return 0;
}

