#include <stdio.h>

int main(void) {
    int num = 0;
    int i = 1;
    int j = 1;
    int factors = 0;
    while (1) {
        num += i;
        factors = 0;
        for (j = 1; j <= num; j++) {
            if (num % j == 0) 
                factors++;
        }
        if (factors > 100) printf("%d: %d\n", num, factors);
        if (factors > 500) {
            printf("%d\n", num);
            break;
        }
        i++;
    }
    return 0;
}
