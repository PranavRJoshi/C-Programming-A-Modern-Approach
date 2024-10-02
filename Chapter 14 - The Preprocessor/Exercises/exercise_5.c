// Q. Let TOUPPER be the following macro:
//    #define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))
// Let s be a string and let i be an int variable. Show the output produced by each of the following program fragments:
//    a.  strcpy(s, "abcd");
//        i = 0;
//        putchar(TOUPPER(s[++i]));
//    b.  strcpy(s, "0123");
//        i = 0;
//        putchar(TOUPPER(s[++i]));

// Let's breakdown the problem, considering the first question
//    
//    NOTE: Remember the fact that macros replaces the invocation by the replacement list, so it does not corcern itself with values of variable, i.e. the place where macro is invoced is replaced as is.
//
//    strcpy(s, "abcd") ---> s = "abcd\0"
//    i = 0
//    putchar(TOUPPER(s[++i])) ---> putchar(TOUPPER(s[++{0}])) ---> putchar(('a' <= (s[++{0}]) && (s[++{0}]) <= 'z' ? (s[++{0}]) - 'a' + 'A' : (s[++{0}])))
//
//    NOTE: {0} indicates the value of i, which is initialized to be 0, and ++{0} indicates the increment of the array subscript. ++0 only would not be easy to understand (also the fact that it may not always remiain 0 through out the statement as the operator used is pre-increment
//    
//    How TOUPPER will work (not considering the case when the macro argument has side effect):
//    TOUPPER('b') ---> ('a' <= 'b' && 'b' <= 'z') ---> 1 && 1 ---> 'b' - 'a' + 'A' ---> 98 - 97 + 65 ---> 66 ---> 'B'
//
//    NOTE: This question has macro argument that produces the side effect. So the behavior is undefined.
//
// For the second question
//    NOTE: This does not consider the fact that the given question has a macro invocation that involves a side effect.
//    strcpy(s, "0123") ---> s = "0123\0"
//    i = 0
//    putchar(TOUPPER(s[++i])) ---> putchar(TOUPPER(s[1]))
//    TOUPPER('1') ---> ('a' <= '1' && '1' <= 'z') ---> 0 && 0 ---> '1'
//
//    Considering the fact that the operator that produces side effect is used as a macro agrument, the result is undefined.

#include <stdio.h>
#include <string.h>

#define STR_LEN 100

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main (void) {

  int i;
  char str[STR_LEN];

  strcpy(str, "abcd");
  i = 0;
  putchar(TOUPPER(str[++i]));

  strcpy(str, "0123");
  i = 0;
  putchar(TOUPPER(str[++i]));

  // Produced the result: D2
  
  // TOUPPER(s[++i]) ---> ('a' <= s[++i] && s[++i] <= 'z' ? s[++i] - 'a' + 'A' : s[++i])

  // if you read the comments above, we can see that str's subcscipt is incremented twice when checking for the condition, and after the evaluation is true, the subscript is again incremented, thus pointing the character d when the character is being translated to upper-case.
  // for the second case, the first condition increments the subscript's value, thus making i = 1. Since the first evaluation is false and C has short-circuit evaluation--the first conditions from the && (logical and) is checked and if it is false, then the second condition is not checked as 0 && <any> is still 0, the second expression is skipped. When the last expression of the ternary operation is carried out, the the subscript is again incremented, thus making it point to the value 2. 

  // The reason why this is undefined is, we cannot really know when the sequence point is reached in the statement.
  
  return 0;
}

