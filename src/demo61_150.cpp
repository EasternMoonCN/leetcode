//
// Created by EasternMoon on 2024/7/9.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) {
            return nullptr;
        }
        if (!k) {
            return head;
        }
        int n = 1;
        ListNode* tail = head, *prev = nullptr;
        while(tail->next) {
            tail = tail->next;
            ++n;
        }
        int lk = n - k % n;
        for(int i = 0; i < lk; ++i) {
            prev = head;
            head = head->next;
            tail->next = prev;
            tail = prev;
        }
        tail->next = nullptr;
        return head;
    }
};

int main() {
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode* head = Solution().rotateRight(&n1, 2);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}
