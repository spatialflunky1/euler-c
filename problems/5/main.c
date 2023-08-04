#include <stdio.h>

int main(void) {
    int num = 1;
    int divByAll = 0;
    while (1) {
        for (int i = 1; i <= 20; i++) {
            if (num % i != 0) break;
            else if (i == 20) divByAll = 1;
        }
        if (divByAll) break;
        num++;
    }
    printf("%d\n", num);
    return 0;
}
