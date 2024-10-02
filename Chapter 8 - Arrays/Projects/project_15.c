// Q. One of the oldest known encryption techniques is the Caesar cipher, attributed to Julius Caesar. It involves replacing each letter in a message with another letter that is a fixed number of positions later in the alphabet. (If the replacement would go past the letter Z, the cipher "wraps around" to the beginning of the alphabet. For example, if each letter is replaced by the letter two positions after it, then Y would be replaced by A, and Z would be replaced by B.) Write a program that encrypts a message using a Caesar cipher. The user will enter the message to be encrypted and the shift amount (the number of positions by which letters should be shifted):
//    Enter message to be encrypted: Go ahead, make my day.
//    Enter shift amount (1-25): 3
//    Encrypted message: Jr dkhdg, pdnh pb gdb.
// Notice that the program can decrypt a message if the user enters 26 minus the original key:
//    Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
//    Enter shift amount (1-25): 23
//    Encrypted message: Go ahead, make my day.
// You may assume that the message does not exceed 80 characters. Characters other than letters should be left unchanged. Lower-case letters remain lower-case when encrypted, and upper-case letters remain upper-case. Hint: To handle the wrap-around problem, use the expression ((ch - 'A') + n) % 26 + 'A' to calculate the encrypted version of an upper-case letter, where ch stores the letter and n stores the shift amount. (You'll need a similar expression for lower-case letters.)

#include <stdio.h>

#define MSG_LENGTH 80

int main (void) {

  char ch;
  char original_message[MSG_LENGTH];
  char encrypted_message[MSG_LENGTH];

  int i;
  int shift_amount;

  printf("Enter message to be encrypted: ");

  for (i = 0, ch = getchar(); ch != '\n'; i++, ch = getchar()) {
    original_message[i] = ch;
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift_amount);

  for (int j = 0; j < i; j++) {
    if (original_message[j] >= 'a' && original_message[j] <= 'z') {
      // when the character x with shift of 4 is encountered
      // 'x' - 'a' (120 - 97) = 23 -> 23 + 4 = 27 -> 27 % 26 -> 1 + 97 -> 98 -> (converting from ASCII number to character) -> b 
      encrypted_message[j] = ((original_message[j] - 'a') + shift_amount) % 26 + 'a';
    } else if (original_message[j] >= 'A' && original_message[j] <= 'Z') {
      // similar to the one as described above, but for upper-case characters
      encrypted_message[j] = ((original_message[j] - 'A') + shift_amount) % 26 + 'A';
    } else {
      // when it encounters a non-alphabetic characters, do nothing.
      encrypted_message[j] = original_message[j];
    }
  }

  printf("Encrypted message: ");

  for (int j = 0; j < i; j++) {
    printf("%c", encrypted_message[j]);
  }

  printf("\n");

  return 0;
}

