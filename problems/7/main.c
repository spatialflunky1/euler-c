/*

    THIS CODE SUCKS DICK AND BALLS
    It's super inefficient
    The code keeps going past the 10001st prime
    But to use Sieve of Eratosthenes (like the most efficient algorithm) it needs to be this way
    I could just be stupid as hell though and there could be a 100% more efficient method


    NEXT DAY UPDATE: holy shit why am I appending to a list of an unchanging size
    just create a fixed size array and set all of the values
    ** updated: removed append for fixing performace

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void sieve(int num) {
    int* arr = malloc((num - 1) * sizeof(int));
    int j;
    for (int i = 0; i < num - 1; i++) arr[i] = 1;
    for (int i = 2; i < sqrt(num)+1; i++) {
        if (arr[i - 2]) {
            j = i*i;
            while (j <= num) {
                arr[j - 2] = 0;
                j += i;
            }
        }
    }

    int current = 0;
    for (int i = 0; i < num - 1; i++) {
        if (arr[i]) current++;
        if (current == 10001 && arr[i]) {
            printf("ANSWER %d\n", i+2);
            exit(0);
        }
    } 
}

int main(void) {
    sieve(120000);
}
