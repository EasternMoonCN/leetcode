#include "utils/link.cpp"
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur) {
            while (cur->next) {
                if (cur->val == cur->next->val) {
                    cur->next = cur->next->next;
                } else {
                    break;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};