#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    
    struct ListNode *current = result;
    struct ListNode *currentL1 = l1;
    struct ListNode *currentL2 = l2;
    int carry = 0;
    while (currentL1 && currentL2) {
        int temp = currentL1 -> val + currentL2 -> val + carry;
        if (temp / 10 > 0) {
            carry = temp % 10;
            temp = 0;
        }
        current -> val = temp;
        current -> next = (struct ListNode *) malloc((sizeof(struct ListNode)));

        current = current -> next;
        currentL1 = currentL1 -> next;
        currentL2 = currentL2 -> next;
    }

    return result;
}

int main(int argc, char **argv) {
    char **L1ENDPTR = NULL;
    char **L2ENDPTR = NULL;
    int length = (argc - 1) / 2;

    struct ListNode *l1 = NULL;
    struct ListNode *currentNodeL1 = l1; 
    struct ListNode *l2 = NULL;
    struct ListNode *currentNodeL2 = l2;
    
    for(int i = 0; i < length; i++) {
        if (!l1 && !l2) {
            l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
            l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
            currentNodeL1 = l1;
            currentNodeL2 = l2;
        } else {
            currentNodeL1 -> next = (struct ListNode *) malloc(sizeof(struct ListNode));
            currentNodeL2 -> next = (struct ListNode *) malloc(sizeof(struct ListNode));
            currentNodeL1 = currentNodeL1 -> next;
            currentNodeL2 = currentNodeL2 -> next;
        }
        
        currentNodeL1 -> val = strtol(argv[i + 1], L1ENDPTR, 10);
        currentNodeL2 -> val = strtol(argv[i + length + 1], L2ENDPTR, 10);
        currentNodeL1 -> next = NULL;
        currentNodeL2 -> next = NULL;
    }

    struct ListNode *result = addTwoNumbers(l1, l2);
    while(result -> val != 0) {
        printf("%d\n", result -> val);
        result = result -> next;
    }
    printf("\n");

    return 0;
}