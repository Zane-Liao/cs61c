#include <stdio.h>

int arr(int *arr, size_t n) {
        int sum = 0;
        for (int i = n; i > 0; i--) {
            sum += !arr[i - 1];
        }
    return ~sum + 1;
}

int baz(int x, int y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    return y;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int mystrlen(char *ch) {
    int sum = 0;
    for (int i = 0; i < *ch++; i++) {
        sum += 1;
    }
    return sum;
}

int sum(int* summands, size_t n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(summands + i);
    }
    return sum;
}

void increment(char* string) {
    while (*string != '\0') {
        (*string)++;
        string++;
    }
}

void copy(char* src, char* dst) {
    while (*src != '\0') {
        *dst++ = *src++;
        src++;
    }
}

void cs61c(char* src, size_t length) {
    char *srcptr, *replaceptr;
    char replacement[16] = "61C is awesome!";
    srcptr = src;
    replaceptr = replacement;
    if (length >= 16) {
    for (int i = 0; i < 16; i++)
        *srcptr++ = *replaceptr++;
    }
}


int main(void) {
    int x = 5;
    int y = 6;
    printf("%d\n", baz(4, 2));
    swap(&x, &y);
    printf("%d , %d\n", x, y);
    int a = mystrlen("Hello cs61c!");
    printf("%d\n", a);
    int z[] = {2, 3, 4};
    printf("%d\n", sum(z, 3));
    char str1[3] = "abc";
    increment(str1);
    printf("%s\n", str1);
    char str2[4] = "ffff";
    char str3[4] = "ffff";
    copy(str2, str3);
    printf("%s", str3);
    char str4[20] = "eeeeeeeeeeeeeeeeeeee";
    cs61c(str4, 20);
    printf("%s", str4);
}