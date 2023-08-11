#include <stdio.h>
#include <inttypes.h>

int main(void) {
    uint64_t n;
    int len = 1;
    int max_len = 0;
    int max_start = 0;
    for (int i = 1; i < 1000000; i++) {
        n = i;
        len = 1;
        while (n != 1) {
            n = n%2==0 ? n/2 : (3*n)+1;
            len++;
        }
        if (len > max_len) {
            max_len = len;
            max_start = i;
        }
    }

    printf("Max Length: %d\n", max_len);
    printf("Max Start: %d\n", max_start);
    return 0;
}
