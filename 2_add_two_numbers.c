// ALL BY MYSELF
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    l3->val = 0;
    l3->next = NULL;
    struct ListNode * p = l3;
    int inc = 0;

    while (1){
        if (l1->next == NULL && l2->next == NULL) {
            p->val = l1->val + l2->val + inc;
            printf("end-->%d, %d, %d, %d\n", l1->val, l2->val, inc, p->val);
            if (p->val > 9) {
                p->val = p->val - 10;
                struct ListNode * np = malloc(sizeof(struct ListNode));
                np->val = 1;
                np->next = NULL;
                p->next = np;
                p = np;
            } 
            p->next = NULL;
            return l3;
        }
        if (l1->next == NULL){
            l1->next = malloc(sizeof(struct ListNode));
            l1->next->val = 0;
            l1->next->next = NULL;
        }
        if (l2->next == NULL ){
            l2->next = malloc(sizeof(struct ListNode));
            l2->next->val = 0;
            l2->next->next = NULL;
        }
        p->val = l1->val + l2->val + inc;
        if (p->val > 9){
            p->val = p->val - 10;
            inc = 1;
        }
        else{
            inc = 0;
        }

        l1 = l1->next;
        l2 = l2->next;

        struct ListNode *np = malloc(sizeof(struct ListNode));

        np->val = 0;

        np->next = NULL;

        p->next = np;

        p = np;
    }
    return l3;
}

int main()
{
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    int array1[9] =  {8,9,4,7,3,5,9,3,2};
    int array2[10] = {8,0,1,0,7,8,8,7,9,1};
    int i;
    for (i = 0; i < 9; i++) {
        p1->val = array1[i];
        p2->val = array2[i];
        if (i != 8) {
            struct ListNode *np1 = malloc(sizeof(struct ListNode));
            np1->val = 0;
            np1->next = NULL;
            p1->next = np1;
            p1 = np1; 
        }
        struct ListNode *np2 = malloc(sizeof(struct ListNode));
        np2->val = 0;
        np2->next = NULL;
        p2->next = np2;
        p2 = np2;
    } 

    p2->val = 1;
    p2->next = NULL;
    struct ListNode *res = addTwoNumbers(l1, l2);
    while (res) {
        printf("%d, ", res->val);
        res = res->next;
    }
    return 0;
}
