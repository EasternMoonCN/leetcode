#include "../utils/link.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        auto cur = &dummy;
        while(cur->next && cur->next->next) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                ListNode* next = cur->next->next;
                while (next->next && next->val == val) {
                    next = next->next;
                }
                cur->next = next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l31 = new ListNode(3);
    ListNode* l32 = new ListNode(3);
    ListNode* l41= new ListNode(4);
    ListNode* l42= new ListNode(4);
    ListNode* l5 = new ListNode(5);


    l1->next = l2;
    l2->next = l31;
    l31->next = l32;
    l32->next = l41;
    l41->next = l42;
    l42->next = l5;

    ListNode* head = Solution().deleteDuplicates(l1);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}