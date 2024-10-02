// Q. Use a series of type definitions to simplify each of the declarations in Exercise 8.

#include <stdio.h>

char question_a (int num);

int (*x(int))[5];

float *(*y(void)) (int);
float *question_c (int);

void question_d (int num);
void (*z(int, void (*)(int)))(int);

int main (void) {

  /* Question 8(a) */
  printf("*** Beginning of Question 8(a) ***\n");
  typedef char td_question_a(int);                // td_question_a is an identifier that is a function which takes in an integer as an argument and returns a character. td_question_a is a function.
  typedef td_question_a *td_question_a_arr[10];   // td_question_a_arr is an array of pointers of size 10 where the elements are of type td_question_a.
  td_question_a_arr ques_a_ans;

  ques_a_ans[0] = question_a;
  ques_a_ans[0](10);
  printf("*** End of Question 8(a) ***\n");

  /* Question 8(b) */
  printf("*** Beginning of Question 8(b) ***\n");
  typedef int td_question_b_arr[5];                             // td_question_b_arr is an array of integers of size 5. 
  typedef td_question_b_arr *td_question_b_arr_ptr;             // td_question_b_arr_ptr is a pointer to td_question_b_arr.
  typedef td_question_b_arr_ptr (*td_question_b_fcn_ptr)(int);  // td_question_b_fcn_ptr is a pointer to a function which takes in an integer as an argument and returns td_question_b_arr_ptr.
  td_question_b_fcn_ptr ques_b_func;
  td_question_b_arr_ptr ques_b_ans;
  ques_b_func = x;
  ques_b_ans = ques_b_func(10);
  for (int i = 0; i < 5; i++) {
    printf("Element %d is: %d\n", i, *(*ques_b_ans + i));
    // printf("Element %d is: %d\n", i, (*ques_b_ans)[i]);    // Alternative

  }
  printf("*** End of Question 8(b) ***\n");

  /* Question 8(c) */
  printf("*** Beginning of Question 8(c) ***\n");
  typedef float *td_ques_c_ptr_fcn(int);                      // td_ques_c_ptr_fcn is a function which takes in an integer as an argument and returns a pointer to a float.
  typedef td_ques_c_ptr_fcn *td_ques_c_ptr_to_fcn;            // td_ques_c_ptr_to_fcn is a pointer to td_ques_c_ptr_fcn.
  typedef td_ques_c_ptr_fcn *td_ques_c_ret_ptr_to_fcn(void);  // td_ques_c_ret_ptr_to_fcn is a function which takes in no argument and returns a pointer to td_ques_c_ptr_fcn.
  typedef td_ques_c_ret_ptr_to_fcn *td_ques_c_ptr_fcn_all;    // td_ques_c_ptr_fcn_all is a pointer to td_ques_c_ret_ptr_to_fcn.
  td_ques_c_ptr_fcn_all ques_c_func;
  td_ques_c_ptr_to_fcn ques_c_ans;
  ques_c_func = y;
  ques_c_ans = ques_c_func();
  (*ques_c_ans)(10);
  printf("*** End of Question 8(c) ***\n");


  /* Question 8(d) */
  printf("*** Beginning of Question 8(d) ***\n");
  typedef void (*td_ques_d_outer_ptr_to_func)(int);                               // td_ques_d_outer_ptr_to_func is a pointer to a function which takes in an integer as an argument and returns void (nothing).
  typedef td_ques_d_outer_ptr_to_func td_ques_d_inner_func(int, void (*)(int));   // td_ques_d_inner_func is a function which takes in two arguments: an integer and a pointer to a function that takes in an integer as an argument and returns void (nothing). td_ques_d_inner_func returns an object of type td_ques_d_outer_ptr_to_func.
  typedef td_ques_d_inner_func *td_ques_d_inner_func_ptr_to_fcn;                  // td_ques_d_inner_func_ptr_to_fcn is a pointer to td_ques_d_inner_func.
  td_ques_d_inner_func_ptr_to_fcn ques_d_func;
  td_ques_d_outer_ptr_to_func ques_d_ans;
  ques_d_func = z;
  ques_d_ans = ques_d_func(10, question_d);
  printf("Calling from the function %s\n", __func__);
  ques_d_ans(10);
  printf("*** End of Question 8(d) ***\n");

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


