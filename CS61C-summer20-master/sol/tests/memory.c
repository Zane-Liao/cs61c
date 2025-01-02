#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    int first;
    struct ll_node* rest;
};

void prepend(struct ll_node** lst, int value) {
    struct ll_node* item = (struct ll_node*) malloc(sizeof(struct ll_node));
    item->first = value;
    item->rest = *lst;
    *lst = item;
}

void free_ll(struct ll_node** lst) {
    if (*lst) {
        free_ll(&((*lst)->rest));
        free(*lst);
    }
}

int main() {
    return 0;
}