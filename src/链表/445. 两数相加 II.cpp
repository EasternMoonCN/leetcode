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
    // ListNode* reverseList(ListNode* head) {
    //     if (!head || !head->next) {
    //         return head;
    //     }
    //     ListNode* dummy = new ListNode(0, head);
    //     ListNode *cur = head, *next = nullptr;
    //     while (cur->next) {
    //         next = cur->next;
    //         cur->next = next->next;
    //         next->next = dummy->next;
    //         dummy->next = next;
    //     }
    //     return dummy->next;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *cur = head, *next = nullptr;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode* dummy = new ListNode();
        int c1 = 0, c2 = 0, over = 0, sum = 0;
        while (l1 || l2 || over) {
            c1 = l1 ? l1->val : 0;
            c2 = l2 ? l2->val : 0;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            sum = c1 + c2 + over;
            over = sum / 10;
            ListNode* node = new ListNode(sum % 10, dummy->next);
            dummy->next = node;
        }
        return dummy->next;
    }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     stack<int> s1, s2;
    //     ListNode* c1 = l1, *c2 = l2;
    //     while (c1) {
    //         s1.push(c1->val);
    //         c1 = c1->next;
    //     }
    //     while (c2) {
    //         s2.push(c2->val);
    //         c2 = c2->next;
    //     }
    //     ListNode *dummy = new ListNode(0);
    //     int t1 = 0, t2 = 0, over = 0, sum = 0;
    //     while (!s1.empty() || !s2.empty() || over) {
    //         t1 = t2 = 0;
    //         if (!s1.empty()) {
    //             t1 = s1.top();
    //             s1.pop();
    //         }
    //         if (!s2.empty()) {
    //             t2 = s2.top();
    //             s2.pop();
    //         }
    //         sum = t1 + t2 + over;
    //         over = sum / 10;
    //         ListNode* node = new ListNode(sum % 10, dummy->next);
    //         dummy->next = node;
    //     }
    //     return dummy->next;
    // }
};