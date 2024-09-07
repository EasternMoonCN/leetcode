//
// Created by EasternMoon on 2024/6/27.
//

#include "link.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// 快慢指针
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }

//    bool hasCycle(ListNode *head) {
//        unordered_set<ListNode *> list_set;
//        while (head) {
//            if (list_set.count(head)) {
//                return true;
//            }
//            list_set.insert(head);
//            head = head->next;
//        }
//        return false;
//    }
};