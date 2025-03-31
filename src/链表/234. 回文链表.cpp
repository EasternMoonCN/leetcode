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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *prev = nullptr, *next = nullptr;
        while (cur) {
            next =cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid);
        // 偶数情况下，head比head2多1，最后一个时相同节点
        // 技术情况下，head和head2一样长，最后一个时相同节点
        while(head2) {
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};