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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int c = 0;
        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = nullptr, *cur = dummy;
        // while (c < left) {
        //     c++;

        //     p0 = cur;
        //     cur = cur->next; 
        // }
        // cur指向left节点，共left个
        for (int i = 0; i < left; ++i) {
            p0 = cur;
            cur = cur->next; 
        }

        // 反转链表:prev为翻转前尾节点，cur为下一节点
        ListNode* prev = nullptr, *next = nullptr;
        // while (c <= right) {
        //     c++;

        //     next = cur->next;
        //     cur->next = prev;
            
        //     prev = cur;
        //     cur = next;
        // }
        // cur指向right+1节点，共right-left+1
        for (int i = 0; i < right - left + 1; ++i) {
            next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }

        p0->next->next = cur;
        p0->next = prev;

        return dummy->next;

    }
};