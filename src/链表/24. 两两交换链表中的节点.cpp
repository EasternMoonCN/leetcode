#include "../utils/link.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* cur = head, *prev = nullptr, *next = nullptr, *p0 = dummy;
        // 保证还有两个节点
        while (cur && cur->next) {
            next = cur->next;
            cur ->next = prev;

            prev = cur;
            cur = next;

            next = cur->next;
            cur ->next = prev;

            prev = cur;
            cur = next;

            next = p0->next;
            next->next = cur;
            p0->next = prev;
            p0 = next;
        }
        return dummy->next;
    }
};