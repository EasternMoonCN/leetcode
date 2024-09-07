//
// Created by EasternMoon on 2024/7/7.
//

#include "utils/link.h"
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
        if (left == right || !head) {
            return head;
        }
        ListNode* pre = nullptr, *succ = nullptr, * cur = head, * start = nullptr;
        int i = 1;
        while (cur && i != left) {
            ++i;
            pre = cur;
            cur = cur->next;
        }
        start = cur;

        while (cur && i != right) {
            ++i;
            cur = cur->next;
        }
        succ = cur->next;
        cur->next = nullptr;
        start->next = succ;
        if (pre == nullptr) {
            return reverse(start);
        } else {
            pre->next = reverse(start);
            return head;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode *pre = nullptr, *next = nullptr;
        while (head)  {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    ListNode* head = Solution().reverseBetween(&n1, 2, 4);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}