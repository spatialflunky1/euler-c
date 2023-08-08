#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
    int num = 0;
    int i = 1;
    int j;
    int factors = 0;
    while (1) {
        num += i;
        factors = 0;
        for (j = 1; j < sqrt(num); j++) {
            if (num % j == 0) {
                factors += 2;
            }
        }
        if (factors > 500) {
            printf("%d: %d\n", num, factors);
            break;
        }
        i++;
    }
    return 0;
}
