// Q. Modify Programming Project 7 so that it prompts for five quiz grades for each of five students, then computes the total score and average score for each student, and the average score, high score and low score for each quiz.

#include <stdio.h>

#define QUIZ_SIZE 5
#define STUDENT_SIZE 5

int main (void) {

  int arr_mat[STUDENT_SIZE][QUIZ_SIZE] = {0};
  int student_total[STUDENT_SIZE] = {0};
  int quiz_total[QUIZ_SIZE] = {0};
  float student_avg[STUDENT_SIZE] = {0.0f};     // initializing with 0.0f makes all the elements initialize to 0.000000
  float quiz_avg[QUIZ_SIZE] = {0.0f};
  // these take STUDENT_SIZE as the array size since we need to consider the total occurance of the particular quiz.
  int quiz_high_score[STUDENT_SIZE] = {0};
  int quiz_low_score[STUDENT_SIZE] = {0};

  // Inout the grades (marks) from the user and store them in elements of arr_mat
  for (int i = 0; i < STUDENT_SIZE; i++) {
    printf("Enter student %d grades: ", i+1);
    for (int j = 0; j < QUIZ_SIZE; j++) {
      scanf("%d", &arr_mat[i][j]);
    }
  }

  // iterate over the arr_mat to add the row total and the column total
  for (int i = 0; i < STUDENT_SIZE; i++) {
    for (int j = 0; j < QUIZ_SIZE; j++) {
      // arr[i][j], where i keeps track of the number of students and j keeps track of number of quizes
      student_total[i] += arr_mat[i][j];
      // we use j as the subscript since quiz total needs to store the total in a particular column
      quiz_total[j] += arr_mat[i][j];
    }
    // calculate the average of the student and store it in student_avg
    student_avg[i] = (float) student_total[i] / QUIZ_SIZE;
  }

  // calculate the average of the quiz score and store it in quiz_avg
  // we use QUIZ_SIZE as it indicates the total number of quizes a student takes
  // and divide it by STUDENT_SIZE to get the average of the score in the particular quiz
  for (int i = 0; i < QUIZ_SIZE; i++) {
    quiz_avg[i] = (float) quiz_total[i] / STUDENT_SIZE;
  }

  // first, store the inital value as the largest and the smallest value 
  // arr_mat[0][i] iterates over the elements of the first row, i.e. from the first student.
  for (int i = 0; i < QUIZ_SIZE; i++) {
    quiz_high_score[i] = arr_mat[0][i];
    quiz_low_score[i] = arr_mat[0][i];
  }
  
  // then check for the largest and the smallest value 
  for (int i = 0; i < QUIZ_SIZE; i++) {
    // since we already took the first sub-array as a reference point, we start from 1
    for (int j = 1; j < STUDENT_SIZE; j++) {
      // check if the number is highest or not
      // arr_mat[j][i] iterates over the column
      if (arr_mat[j][i] > quiz_high_score[i]) {
        quiz_high_score[i] = arr_mat[j][i];
      }
      // check if the number is lowest or not
      if (arr_mat[j][i] < quiz_low_score[i]) {
        quiz_low_score[i] = arr_mat[j][i];
      }
    }
  }

  // display the Student's total grade (marks)
  printf("Student's total grade: ");
  for (int i = 0; i < STUDENT_SIZE; i++) {
    printf("%d ", student_total[i]);
  }
  
  printf("\n");

  // display the Student's average (marks)
  printf("Student's average grade: ");
  for (int i = 0; i < STUDENT_SIZE; i++) {
    printf("%.2f ", student_avg[i]);
  }
  
  printf("\n");


  // display the quiz's average
  printf("Quiz's average: ");
  for (int i = 0; i < QUIZ_SIZE; i++) {
    printf("%.2f ", quiz_avg[i]);
  }

  printf("\n");

  // display the high score for each quiz
  printf("Quiz's highest scores: ");
  for (int i = 0; i < QUIZ_SIZE; i++) {
    printf("%d ", quiz_high_score[i]);
  }

  printf("\n");

  // display the low score for each quiz
  printf("Quiz's lowest scores: ");
  for (int i = 0; i < QUIZ_SIZE; i++) {
    printf("%d ", quiz_low_score[i]);
  }

  printf("\n");

  return 0;
}


