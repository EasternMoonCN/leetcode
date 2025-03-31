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
    ListNode* prev;
    bool flag = true;
    void reorderList(ListNode* head) {
        prev = head;
        dfs(head);
    }

    void dfs(ListNode* curr) {
        if (!curr) {
            return;
        }

        dfs(curr->next);
        if (!flag) {
            return;
        }
        // 偶数时相等，基数时下一个
        if (prev != curr && prev ->next != curr) {
            curr->next = prev->next;
            prev->next = curr;
            prev = curr->next;
        } else {
            curr->next = nullptr;
            flag = false;
        }
    }




    void reorderList2(ListNode* head) {
        ListNode* mid = getMid(head);

        ListNode* next = mid->next;
        mid->next = nullptr;

        ListNode* rhead = reverse(nullptr, next);
        merge(head, rhead);
    }

    ListNode* getMid(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* prev, ListNode* head) {
        ListNode* next = head->next;
        head->next = prev;
        if (!next) {
            return head;
        }
        return reverse(head, next);
    }

    void merge(ListNode* h1, ListNode* h2) {
        while (h2) {
            ListNode* temp = h1->next;
            h1->next = h2;
            h2 = h2->next;
            h1 = temp;
        }
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;
    Solution().reorderList2(l1);
    while (l1)
    {
        cout << l1->val << " " << endl;
        l1 = l1->next;
    }
    
}