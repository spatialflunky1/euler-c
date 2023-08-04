#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

void primeSum(int limit) {
    int* arr = malloc((limit-1) * sizeof(arr));
    int j;
    for (int i = 0; i < limit - 1; i++) arr[i] = 1;
    printf("All appended\n");
    for (int i = 2; i < sqrt(limit)+1; i++) {
        if (arr[i - 2]) {
            j = i*i;
            while (j <= limit) {
                arr[j - 2] = 0;
                j += i;
            }
        }
    }

    uint64_t total = 0;
    for (int i = 0; i < limit; i++) {
        if (arr[i]) total += (i + 2);
    }

    free(arr);
    printf("%"PRIu64"\n", total);
}

int main(void) {
    primeSum(2000000);
}
