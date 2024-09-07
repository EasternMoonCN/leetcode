//
// Created by EasternMoon on 2024/7/10.
//
#include "utils/link.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(), *large = new ListNode();
        ListNode* smallCur= small, *largeCur = large;
        while(head) {
            if (head->val < x) {
                smallCur->next = head;
                smallCur = smallCur->next;
            } else if (head->val >= x) {
                largeCur->next = head;
                largeCur = largeCur->next;
            }
            head = head->next;
        }
        if(small != smallCur) {
            head = small->next;
            smallCur->next = large->next;
        } else {
            head = large->next;
        }
        largeCur->next = nullptr;
        delete small, large;
        return head;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2, &n1);
    ListNode n3(3, &n2);
    ListNode n4(4, &n3);
    ListNode n5(5, &n4);
    ListNode* head = Solution().partition(&n5, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}