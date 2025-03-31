#include "utils/link.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> lset;
        while (head) {
            if (lset.count(head)) {
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }
};