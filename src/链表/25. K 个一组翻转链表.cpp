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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode *cur = head;
        // 链表长度
        while (cur) {
            ++len;
            cur = cur->next;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy, *next = nullptr;
        cur = head;
        // 反转len/k次
        for (int i = 0; i < len / k; ++i) {
            ListNode* prev = nullptr;
            for (int j = 0; j < k; ++j) {
                next = cur->next;
                cur->next = prev;

                prev = cur;
                cur = next;
            }

            p0->next->next = cur;

            // 下一次开始的头节点
            next = p0->next;
            p0->next = prev;
            p0 = next;
        }
        return dummy->next;
    }
};