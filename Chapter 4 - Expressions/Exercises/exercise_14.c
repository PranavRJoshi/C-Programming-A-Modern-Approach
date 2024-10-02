// Supply parantheses to show how a C compiler would interpret each of the following expressions:
//     a. a * b - c * d + e -> (a * b) - (c * d) + e -> ((a * b) - (c * d)) + e -> (((a * b) - (c * d)) + e)
//     Expected Answer: (((12 * 20) - (25 * 31)) + 88) -> ((240 - 775) + 88) -> -535 + 88 -> -447
//     Actual Answer: -447
//     b. a / b % c / d -> (a / b) % c / d -> ((a / b) % c) / d -> (((a / b) % c) / d)
//     Expected Answer: (((12 / 20) % 25) / 31) -> ((0 % 25) / 31) -> (0 / 31) -> 0
//     Actual Answer: 0
//     c. - a - b + c - + d -> (- a) - b + c - (+ d) -> ((- a) - b) + c - (+ d) -> (((- a) - b) + c) - (+ d) -> ((((- a) - b) + c) - (+ d))
//     Expected Answer: ((((- 12) - 20) + 25) - (+ 31)) -> (((-32) + 25) - (+ 31)) -> (-7) - (+ 31) -> -38
//     Actual Answer: -38
//     d. a * - b / c - d -> a * (- b) / c - d -> (a * (- b)) / c - d -> ((a * (- b)) / c) - d -> (((a * (- b)) / c) - d)
//     Expected Answer: (((12 * (- 20)) / 25) - 31) -> (((-240) / 25) - 31) -> ((-9) - 31) -> -40
//     Actual Answer: -40

#include <stdio.h>

int main (void) {
    int a, b, c, d, e;
    a = 12; b = 20; c = 25; d = 31; e = 88;

    printf("a * b - c * d + e = %d\n", a * b - c * d + e);

    printf("a / b %% c / d = %d\n", a / b % c / d);

    printf("- a - b + c - + d = %d\n", - a - b + c - + d);

    printf("a * - b / c - d = %d\n",a * - b / c - d);

    return 0;
}
