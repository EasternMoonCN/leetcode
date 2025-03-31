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
    // 头节点不会删除，不必创建dummy
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head, *next = nullptr;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                next = cur->next;
                cur->next = next->next;
                delete next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};