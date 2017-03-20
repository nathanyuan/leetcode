#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *p1 = head;
    struct ListNode *p2 = p1;
    head = head->next;

    while (p1) {
        if (p1->next == NULL)
            return head;
        struct ListNode *t = p1->next->next;
        p2->next = p1->next;
        p2 = p1;
        p1->next->next = p1;
        p1->next = t;
        p1 = t;
    }
    return head;
}

int main()
{
    struct ListNode dummy;
    struct ListNode *p = &dummy;
    int a[] = {1, 2, 3, 4};
    int i;
    for (i = 0; i < 4; i++) {
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = a[i];
        p->next = NULL;
    }
    p = dummy.next;
    while (p) {
        printf("%d, ", p->val);
        p = p->next;
    }
    printf("\n");
    struct ListNode *res = swapPairs(dummy.next);    
    while (res) {
        printf("%d, ", res->val);
        res = res->next;
    }
    return 0;
}
