// Q. Show the output of the following program and explain what it does:
//    #include <stdio.h>
//
//    int f1(int (*f)(int));
//    int f2(int i);
//
//    int main(void)
//    {
//      printf("Answer: %d\n", f1(f2));
//      return 0;
//    }
//
//    int f1(int (*f)(int))
//    {
//      int n = 0;
//
//      while ((*f)(n)) n++;
//      return n;
//    }
//
//    int f2(int i)
//    {
//      return i * i + i - 12;
//    }
// My Answer:
//    1. When f1 is called from main function, with f2 as it's argument, which is valid as f1 is expecting a parameter of type "function pointer" which take one int as it's parameter.
//    2. On the function f1, n is a local variable initialized as 0. In the while loop, function f2 is called with 0 as it's arugment, and in function f2, 0 * 0 + 0 - 12 == -12 is returned. 
//    3. As it is not 0--the termination condition for a loop--n is incremented, and n is now 1. Again the function f2 is called. So f2 is now called as f2(1). In f2, 1 * 1 + 1 - 12 == -10 is returned. Again, loop is not terminated and n is computed again. In tabular representation:
//    n         n * n + n - 12          f2(n)
//    0             -12                  -12
//    1             -10                  -10
//    2             -6                   -6
//    3              0                    0     
// 
// Notice that when n is 3, and f2 is called with n as its argument, f2 will return 0, which is indeed a valid loop termination condition. So the loop will terminate, and f1 will return n--which is 3--to the main function. Hence, the output will be:
//    Answer: 3
//
// Actual Output: 3, as expected.
//
// NOTE: We can replace f1(f2) with f1(&f2), as f1 is expecting a pointer to a function which takes one int as a parameter and returns an int. Also, (*f)(n) in the while statement can be replaced with f(n), see #57 of Chapter's notes.

#include <stdio.h>

int f1 (int (*f)(int));
int f2 (int i);

int main (void) {
  printf("Answer: %d\n", f1(f2));
  return 0;
}

int f1(int (*f)(int)) {
  int n = 0;

  while ((*f)(n)) {
    n++;
  }
  
  return n;
}

int f2(int i) {
  return i * i + i - 12;
}

