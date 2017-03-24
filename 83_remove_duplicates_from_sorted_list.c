#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *p1 = head;
    struct ListNode *p2 = p1->next;
    while (p2) {
        if (p2->val == p1->val)
            p1->next = p2->next; 
        else
            p1 = p2;
        p2 = p2->next;           
    }
    return head;
}

int main()
{
    return 0;
} 
