// The following concept works similar when using the decrement operator

#include <stdio.h>

int main (void) {
    int i = 1;

    printf("The value of i is (pre-increment): %d\n", ++i);
    printf("The value of i is: %d\n", i);

    int j = 1;

    printf("The value of j is (post-increment): %d\n", j++);
    printf("The value of j is: %d\n", j);

    return 0;
}
