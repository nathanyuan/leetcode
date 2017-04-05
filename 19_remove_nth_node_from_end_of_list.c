#include <cstdlib>
#include <vector>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *p1 = head;
        std::vector<struct ListNode*> v;
        int size;
        while (p1) {
            v.push_back(p1);    
            p1 = p1->next;
        }
        size = v.size();
        if (size == n) {
            p1 = head;
            head = head->next;
            delete p1;
            p1 = NULL;
            return head;
        }
        v[size-n-1]->next = v[size-n]->next;
        delete v[size-n];
        v[size-n] = NULL;
        return head;
    }
};
