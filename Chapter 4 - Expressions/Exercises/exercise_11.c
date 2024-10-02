// Q. Show the output produced by each of the following program fragments. Assume that i, j, and k are int variables.
// a. i = 1;
//    printf("%d ", i++ - 1);
//    printf("%d", i);
// Expectation: Here, the first printf should display 0 as i++ first fetches the value of i to the printf then subtracts -1 from it making the result 0. The second printf will have the updated value of i, so it displays 2. -> 0 2
// Actual: 0 2
// b. i = 10; j = 5;
//    printf("%d ", i++ - ++j);
//    printf("%d %d", i, j);
// Expectation: Here, the first printf will display 4 as i is first fetched and only in the later statements its value is incremented by 1 while the value of j is first incremented and then only fetched, so we 4 as the result and the second printf displays 11 and 6 for i and j respectively. -> 4 11 6
// Actual: 4 11 6
// c. i = 7; j = 8;
//    printf("%d ", i++ - --j);
//    printf("%d %d", i, j);
// Expectation: Similar to question number b, the first printf will display 0 as the value of i++ fetched will be 7 and 8 only in later statements while the value of --j will be 7 on the first printf itself. The second printf will display the value of i and j as 8 and 7 respectively. -> 0 8 7
// Actual: 0 8 7
// d. i = 3; j = 4; k = 5;
//    printf("%d ", i++ - j++ + --k);
//    printf("%d %d %d", i, j, k);
// Expectation: The first printf should display ((3 - 4) + 4) -> 3 as the value of i and j are incremented in later statements but the value of k is decremented in the same statment. The second printf will display the value of i, j, and k as 4 5 4 respectively. -> 3 4 5 4
// Actual: 3 4 5 4

#include <stdio.h>

int main (void) {
    int i, j, k;

    i = 1;
    printf("%d ", i++ - 1);
    printf("%d\n", i);

    i = 10; j = 5;
    printf("%d ", i++ - ++j);
    printf("%d %d\n", i, j);

    i = 7; j = 8;
    printf("%d ", i++ - --j);
    printf("%d %d\n", i, j);

    i = 3; j = 4; k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d\n", i, j, k);

    return 0;
}
