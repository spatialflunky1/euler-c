#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

void euler3(uint64_t num);
int isPrime(uint64_t num);
uint64_t stouint64(char* num);

void euler3(uint64_t num) {
    uint64_t max = 0;
    for (uint64_t i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (isPrime(i) && i > max) {
                max = i;
            }
            if (isPrime(num / i) && (num / i) > max) {
                max = num / i;
            }
        }
    }
    printf("%"PRIu64"\n", max);
}

int isPrime(uint64_t num) {
    int prime = 1;
    uint64_t factor = 2;
    while (prime) {
        if (factor > sqrt(num)) break;
        if (num % factor == 0) prime = 0;
        factor++;
    }
    return prime;
}

uint64_t stouint64(char* num) {
    uint64_t total = 0;
    for (int i = 0; i < strlen(num); i++) {
        total = (total * 10) + (num[i]-48);
    }
    return total;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Invalid number of parameters\n");
        return 1;
    }
    else {
        uint64_t num = stouint64(argv[1]);
        if (strlen(argv[1]) > 20 || (strlen(argv[1]) == 20 && (argv[1][0] != '1' || num < 10000000000000000000))) {
            fprintf(stderr, "Number is too large\n");
            return 1;
        }
        else {
            euler3(num);
        }
    }

    return 0;
}
