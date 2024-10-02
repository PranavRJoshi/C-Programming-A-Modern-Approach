// Q. Modify Programming Project 14 from Chapter 8 so that it uses a pointer instead of an integer to keep track of the current position in the array that contains the sentence.

#include <stdio.h>

int main (void) {

  char original_sentence[50];
  char *msg_ptr = original_sentence;
  char terminating_char;
  char ch;
  int i;

  printf("Enter a sentence: ");

  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    if (ch == '.' || ch == '?' || ch == '!') {
      terminating_char = ch;
      break;
    }
    *(msg_ptr + i) = ch;
  }

  printf("Reversal of sentence: ");

  int j = i - 1;

  while (j >= 0) {
    int letter_count = 0;

    while ((*(msg_ptr + j) != ' ') && j >= 0) {
      letter_count++;
      j--;
    }

    for (int k = letter_count - 1; k >= 0; k--) {
      putchar(*(msg_ptr+i-k-1));
    }
    
    if (j >= 0) {
      printf(" ");
      i = i - letter_count - 1;
      j--;
    }
  }

  printf("%c\n", terminating_char);

  return 0;
}

