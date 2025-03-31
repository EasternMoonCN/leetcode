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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *cur = head, *next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next =prev;

            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseListDfs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);


    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode* head = Solution().reverseListDfs(l1);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}