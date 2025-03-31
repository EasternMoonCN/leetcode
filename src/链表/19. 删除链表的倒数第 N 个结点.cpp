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
    // 可能删除头节点，需要创建dummy节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* right = dummy, *left = dummy;

        // 到第n个
        for (int i = 0; i < n; ++i) {
            right = right->next;
        }

        // left，right中间具体n个，left到第n-1个
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        ListNode* next = left->next;
        left->next = next->next;
        delete next;
        return dummy->next;
    }
};