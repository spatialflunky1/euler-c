#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int isPalindrome(char* str);
char* itoc(int num);

int isPalindrome(char* str) {
    int len = strlen(str);
    char* tmp = malloc((strlen(str) * sizeof(char)) + sizeof(char));
    if (tmp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        tmp[len - i - 1] = str[i];
    }
    tmp[len] = '\0';
    int result = strcmp(str, tmp);
    free(tmp);
    if (result == 0) return 1;
    else return 0;
}

char* itoc(int num) {
    int len = 0;
    int tmp = num;
    while (tmp != 0) {
        tmp /= 10;
        len++;
    }
    char* temp = num != 0 ? 
        malloc(sizeof(char) * (int)log10(num)) : 
        malloc(sizeof(char) * (int)log10(1));
    if (temp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    snprintf(temp, len + 1, "%d", num);
    return temp;
}

void intAppend(int val, int** arr, int* len) {
    int* temp = malloc(((*len) + 1) * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }
    for (int i = 0; i < (*len); i++) {
        temp[i] = (*arr)[i];
    }
    temp[(*len)] = val;
    free((*arr));
    (*len)++;
    (*arr) = temp;
}

int maxArr(int* arr, int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main(void) {
    char* result = NULL;
    int* arr = NULL;
    int len = 0;
    for (int i = 999; i > 0; i--) {
        for (int j = 999; j > 0; j--) {
            result = itoc(i * j);
            if (isPalindrome(result)) {
                intAppend(i * j, &arr, &len);
            }
            free(result);
        }
    }
    printf("%d\n", maxArr(arr, len));
    free(arr);
    return 0;
}
