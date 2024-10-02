#include <stdio.h>

void print_detail (int (*p)[5]) {
    int i = 0;
    int (*x)[5] = p;

    printf("The size of the pointer pointing to an array of integer: %zu\n", sizeof(*x));
    for (; p < x + 5; p++) {
        while (i < 5) {
           printf("The element is: %d\n", *((*p) + i));
           i++;
        }
        i = 0;
    }
}

int main (void) {

    int x[5][5] = {{1,2,3,4,5},
                   {5,4,3,2,1},
                   {2,4,6,8,10},
                   {1,3,5,7,9},
                   {0,0,0,0,0}};

    int y[8] = {2, 2, 3, 4, 5, 6, 7, 8};

    int *b = &y[1], *c = &y[5];
    int *d = y;
    printf("The expression is: %d\n", d[0] == y[0]);

    printf("The difference of two pointers are: %ld\n", b-c);
    printf("The value stored at d is: %d\n", *d);

    int i = 0;

    int (*p)[5];

    print_detail(x);

    for (p = x; p < x + 5; p++) {
        (*p)[i] = 0;
    }

    for (p = x; p < x + 5; p++) {
        printf("Cleared out value is: %d\n", (*p)[i]);
    }



    return 0;
}