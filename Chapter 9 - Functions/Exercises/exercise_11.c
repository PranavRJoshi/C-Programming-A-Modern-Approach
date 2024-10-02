// Q. Write the following function:
//    float compute_GPA (char grades[], int n);
// The grades array will contain letter grades (A, B, C, D, or F, either upper-case or lower-case); n is the length of the array. The function should return the average of the grades (assume that A = 4, B = 3, C = 2, D = 1, and F = 0).

#include <stdio.h>

#define LEN 5

float compute_GPA (char grades[], int n);

int main (void) {

  char grades[LEN];
  float gpa_avg = 0.0f;
  int grade_count = 0;
  char ch;

  printf("The program takes in input of: a/A (4 points), b/B (3 points), c/C (2 points), d/D (1 point), f/F (0 point)\n");
  printf("Enter the grades of %d subjects: ", LEN);

  // taking characters from input stream using scanf is an actual pain
  // if we use a for loop that iterates for LEN time, and have the loop body contain scanf
  // then there arises the issue that scanf will put the space character in the grades array
  // putting space in the format string of scanf to indicate that ignore one or more white spaces, like scanf("%c ", grades[i]);
  // might be the first intuition, but it does not work as intended
  // so i end up using the getchar as it is relatively less of a hassle
  while ((ch = getchar()) != '\n') {
    // when the number of grades character that can be allocated in grades is filled, we need to break out of the loop
    // granted this does not automatically flush the input stream if there was more characters than required.
    if (grade_count == LEN) {
      break;
    }
    // check if the character is not a space
    if (ch != ' ') {
      grades[grade_count] = ch;
      grade_count++;
    }
  }

  gpa_avg = compute_GPA(grades, LEN);

  printf("The average of the grades provides is: %.2f\n", gpa_avg);

  return 0;
}

float compute_GPA (char grades[], int n) {
  int grade_value = 0;

  for (int i = 0; i < n; i++) {
    switch (grades[i]) {
      case 'a': case 'A':
        grade_value += 4;
        break;
      case 'b': case 'B':
        grade_value += 3;
        break;
      case 'c': case 'C':
        grade_value += 2;
        break;
      case 'd': case 'D':
        grade_value += 1;
        break;
      default:
        grade_value += 0;
        break;
    }
  }

  return (float) grade_value / n;
}

