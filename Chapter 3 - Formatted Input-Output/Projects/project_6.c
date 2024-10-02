// Q. Modify the addfrac.c program in Section 3.2 so that the user enters both fractions at the same time, separated by a plus sign:
// Enter two fractions separated by a plus sign: 5/6+3/4
// The sum is 38/24

#include <stdio.h>

int main (void) {
    int num_1, num_2;
    int denom_1, denom_2;
    // int result_num, result_denom;

    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num_1, &denom_1, &num_2, &denom_2);

    printf("The sum is: %d/%d\n", (num_1*denom_2 + num_2*denom_1), (denom_1*denom_2));

    return 0;
}
