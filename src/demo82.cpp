//
// Created by EasternMoon on 2024/7/9.
//
#include "utils/link.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next = head->next;
        while (cur && next) {
            if (next && cur->val == next->val) {
                while (next && cur->val == next->val) {
                    cur = next;
                    next = next->next;
                }
                if (prev) {
                    prev->next = next;
                } else {
                    head = next;
                }
            } else {
                prev = cur;
            }
            cur = next;
            next = next->next;
        }
        return head;
    }
};

int main() {
    /*ListNode n5(5);
    ListNode n42(4, &n5);
    ListNode n41(4, &n42);
    ListNode n32(3, &n41);
    ListNode n31(3, &n32);
    ListNode n2(2, &n31);
    ListNode n1(1, &n2);
     */

    ListNode n11(1);
    ListNode n1(1, &n11);
    ListNode* head = Solution().deleteDuplicates(&n1);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}