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
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }

        
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->next && cur->next->val > 4) {
                cur->val = (cur->val * 2 + 1) % 10;
            } else {
                cur->val = cur->val * 2 % 10;
            }
        }
        return head;
    }

    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr, *cur = head, *next = nullptr;
    //     // 遍历完时，prev指向原先链表尾，cur指向nullptr
    //     while (cur) {
    //         next = cur->next;
    //         cur->next =prev;
    //         prev = cur;
    //         cur = next;
    //     }
    //     return prev;
    // }

    // ListNode* doubleIt(ListNode* head) {
    //     head = reverseList(head);
    //     ListNode* cur = head, *dummy = new ListNode();
    //     int over = 0, num = 0;
    //     while (cur) {
    //         num = cur->val * 2 + over;
    //         cur = cur->next;
    //         over = num / 10;
    //         ListNode* node = new ListNode(num % 10, dummy->next);
    //         dummy->next = node;
    //     }
    //     if (over) {
    //         ListNode* node = new ListNode(over, dummy->next);
    //         dummy->next = node;
    //     }
    //     return dummy->next;
    // }
};