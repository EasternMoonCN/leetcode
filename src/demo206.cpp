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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr, *next = nullptr, *cur = head;
        while(cur) {
            // 记录下一个
            next = cur->next;
            // 更新下一个
            cur->next = pre;
            // 更新下一轮遍历
            pre = cur;
            cur = next;
        }
        return pre;
    }
    /*
        ListNode* reverseList(ListNode* head) {
            return dfs(nullptr, head);
        }

        ListNode* dfs(ListNode* pre, ListNode* cur) {
            if(!cur) {
                return pre;
            }
            ListNode* next = cur->next;
            cur->next = pre;
            return dfs(cur, next);
        }
        */
};