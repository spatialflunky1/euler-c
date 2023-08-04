#include <stdio.h>

#define MAX 1000

int main(void) {
    int total = 0;

    for (int i = 0; i < MAX; i++) {
        total += (i % 3 == 0 || i % 5 == 0) ? i : 0;
    }
    printf("%d\n", total);
    
    return 0;
}
