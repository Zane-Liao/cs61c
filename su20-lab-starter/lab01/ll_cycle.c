#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    
    struct node* temp = head;
    struct node* prev = head;
    while (prev != NULL && prev->next != NULL) {
        temp = temp->next;
        prev = prev->next->next;
        
        if (temp == prev) {
            return 1;
        }
    }
    return 0;
}