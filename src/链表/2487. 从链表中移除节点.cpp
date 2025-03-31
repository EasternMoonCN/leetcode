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

    // ListNode* removeNodes(ListNode* head) {
    //     head = reverseList(head);
    //     auto cur = head;
    //     int val = head->val;
    //     while (cur->next) {
    //         if (cur->next->val < val) {
    //             cur->next = cur->next->next;
    //         } else {
    //             cur = cur->next;
    //             val = cur->val;
    //         }
    //     }
    //     return reverseList(head);
    // }

    ListNode* removeNodes(ListNode* head) {
        if (!head->next) {
            return head;
        }

        // 是最大节点
        auto next = removeNodes(head->next);
        if (head->val < next->val) {
            // 删除head
            return next;
        } else {
            // 不删除(重新进行了关系链接)
            head->next = next;
            return head;
        }

    }
};