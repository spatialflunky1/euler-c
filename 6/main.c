#include <stdio.h>

#define MAX 100

int main(void) {
    int sumSquare = 0;
    for (int i = 1; i <= MAX; i++) sumSquare += i*i;
    int squareSum = 0;
    for (int i = 1; i <= MAX; i++) squareSum += i;
    squareSum *= squareSum;

    printf("%d\n", squareSum - sumSquare); 
    return 0;
}
