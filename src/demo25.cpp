//
// Created by EasternMoon on 2024/7/16.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return dfs(nullptr, head, 0, k);
    }

    ListNode* dfs(ListNode* pre, ListNode* cur, int i, int k) {
        if (!cur) {
            return nullptr;
        }
        ListNode* next = cur->next;
        if (i == k) {
            cur->next = pre;
        }
        dfs(cur, next, i + 1, k);
    }

    ListNode* reverseKGroup2(ListNode* head, int k) {
        int i = 0;
        stack<ListNode* > stack_node;
        ListNode* dummy = new ListNode(), *cur = dummy, *start = nullptr;
        while (head) {
            if (!start) {
                start = head;
            }
            stack_node.push(head);
            head = head->next;
            ++i;
            if (i == k) {
                while (!stack_node.empty()) {
                    cur->next = stack_node.top();
                    cur = cur->next;
                    stack_node.pop();
                }
                i = 0;
                start = nullptr;
            }
        }
        if (!stack_node.empty()) {
            stack_node.top()->next = nullptr;
            cur->next = start;
        } else {
            cur->next = nullptr;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2, &n1);
//    ListNode n3(3, &n2);
//    ListNode n4(4, &n3);
//    ListNode n5(5, &n4);
    ListNode* head = Solution().reverseKGroup(&n2, 2);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}