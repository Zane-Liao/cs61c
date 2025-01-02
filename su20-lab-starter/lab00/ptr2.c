#include <stdio.h>
// Dangling Pointer for example
int *ptr() {
    int y;
    y = 3;
    return &y; // y has been drop.
}

int main(void) {
    int *stackAddr, content;
    stackAddr = ptr();
    content = *stackAddr;
    printf("%d\n", content); 
    content = *stackAddr;
    printf("%d\n", content);
}