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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *prev = nullptr, *next = nullptr;
        while (cur) {
            next =cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }
        return prev;
    }

    void merge(ListNode* h1, ListNode* h2) {
        while (h2->next) {  // 最后一个元素不会参与
            ListNode* n1 = h1->next;
            ListNode* n2 = h2->next;

            h1->next = h2;
            h2->next = n1;

            h1 = n1;
            h2 = n2;
        }
    }

    void reorderList(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* h2 = reverseList(mid);
        // 奇数情况下，h1h2长度相同，尾巴都指向同一个元素
        // 偶数情况下，h1长度大于h2, 尾巴都指向同一个元素
        merge(head, h2);
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    // ListNode* l5 = new ListNode(5);


    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    // l4->next = l5;

    Solution().reorderList(l1);

    ListNode* head = l1;
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}