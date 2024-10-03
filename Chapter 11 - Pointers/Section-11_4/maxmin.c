// Q. Let's look at a function named max_min that finds the largest and smallest elements in array. When we call max_min, we'll pass it pointers to two variables: max_min will then store its answers in these variables. max_min has the following prototype:
//    void max_min (int a[], int n, int *max, int *min);
// A call of max_min might have the following appearance:
//    max_min (b, N, &big, &small);
// b is an array of integers; N is the number of elements in b. big and small are ordinary integer variables. When max_min finds the largest element in b, it stores the value in big by assuming it to *max. (Since max points to big, an assignment to *max will modify the value of big.) max_min stores the smallest element of b in small by assigning it to *min.

#include <stdio.h>

#define N 10

void max_min (int a[], int n, int *max, int *min);

int main (void) {

  int b[N] = {0};
  int max, min;

  printf("Enter %d numbers: ", N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  max_min(b, N, &max, &min);

  printf("The largest number is: %d\n", max);
  printf("The smallest number is: %d\n", min);

  return 0;
}

void max_min (int a[], int n, int *max, int *min) {
  *max = *min = a[0];

  for (int i = 0; i < n; i++) {
    if (a[i] > *max) {
      *max = a[i];
    }
    if (a[i] < *min) {
      *min = a[i];
    }
  }
}
