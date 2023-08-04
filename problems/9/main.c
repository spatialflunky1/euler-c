#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stoi(char* str) {
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) num = (num * 10) + ((int)str[i] - 48);
    }
    return num;
}

int triplets(int num) {
    for (int a = 1; a < num; a++) {
        for (int b = a; b < num; b++) {
            if ((a*a) + (b*b) == (num*num) && a+b+num==1000) {
                printf("%d^2 + %d^2 == %d^2\n", a, b, num);
                printf("%d + %d + %d == 1000\n", a, b, num);
                printf("%d * %d * %d == %d\n", a, b, num, a*b*num);
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    for (int c = 1; c < 1000; c++) {
        if (triplets(c)) break;
    }
    return 0;
}
