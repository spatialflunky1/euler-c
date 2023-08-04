#include <stdio.h>

int main(void) {
    int total = 1;
    int tmp = 0;
    int prev = 1;
    int sum = 0;
    while (1) {
        if (total % 2 == 0) sum += total;
        if (total + prev > 4000000) break;
        tmp = total;
        total += prev;
        prev = tmp;
    }
    printf("%d\n", sum);

    return 0;
}
