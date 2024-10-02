// Q. Write a complete description of the type of x as specified by each of the following declarations.
//     a. char (*x[10])(int);
//     b. int (*x(int))[5];
//     c. float *(*x(void))(int);
//     d. void (*x(int, void (*)(int)))(int);

// a. x is an array of pointers of size 10 that has elements of type functions pointer that takes in an integer as an argument and returns a character.
// b. x is a function that takes in integer as an argument and returns a pointer to an array of type integer of size 5.
// c. x is a function that takes in no argument and returns a pointer to a function that takes an integer and returns a pointer of type float.
// d. x is a function which takes in two arguments: an integer and a pointer to a function that has integer as an argument and returns void, returns a pointer to a function that takes an integer as an argument and returns void.

#include <stdio.h>

char question_a (int num);

int (*x(int))[5];

float *(*y(void)) (int);
float *question_c (int);

void question_d (int num);
void (*z(int, void (*)(int)))(int);

int main (void) {

  int (*ques_b_res)[5];

  float *(*ques_c_ans)(int);

  void (*ques_d_ans)(int);

  /* Question 8(a) */
  char (*ques_a_res[10])(int);
  ques_a_res[0] = question_a;
  ques_a_res[0](10);

  /* Question 8(b) */
  ques_b_res = x(10);
  for (int i = 0; i < 5; i++) {
    printf("Element %d is: %d\n", i, *(*ques_b_res + i));
    // printf("Element %d is: %d\n", i, (*ques_b_res)[i]);    // Alternative
  }

  /* Question 8(c) */
  ques_c_ans = y();
  (*ques_c_ans)(10);

  /* Question 8(d) */
  ques_d_ans = z(10, question_d);
  printf("Calling from the function %s\n", __func__);
  ques_d_ans(10);

  return 0;
}

char question_a (int num) {
  printf("The number provided is: %d\n", num);

  return 'q';
}

int (*x(int num))[5] {
  static int temp[5];

  for (int i = 0; i < 5; i++) {
    temp[i] = i + num;
  }

  return &temp;
}

float *question_c (int num) {
  static float x;
  x = (float) num;

  printf("The number %d in floating format is: %.2f\n", num, x);

  return &x;
}

float *(*y(void)) (int) {
  return &question_c;
}

void question_d (int num) {
  printf("The function %s was called with the integer %d\n", __func__, num);
}

void (*z(int num, void (*pf)(int innter_num)))(int outer_num) {
  printf("Statements from function %s\n", __func__);

  printf("The provided number is: %d\n", num);
  (*pf)(10);

  printf("Ending the function %s\n", __func__);

  return &question_d;
}
