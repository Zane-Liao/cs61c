#include <stdio.h>

int add_one(int a) {
    return a + 1;
}

void ptr_add_one(int *p) {
    *p = *p + 1;
}

void IncrementPtr(int **h) {
    *h = *h + 1;
}

int main(void) {
    int x = 5;
    add_one(x);
    printf("%d\n", x);
    ptr_add_one(&x);
    printf("%d\n", x);
    int A[3] = {50, 60, 70};
    int *q = A;
    IncrementPtr(&q);
    printf("%d\n", *q);
}