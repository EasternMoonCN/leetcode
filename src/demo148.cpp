#include "utils/link.h"


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        dfs(head, getTail(head));
        return head;
    }

    void dfs(ListNode*& head, ListNode* tail) {
        if (head == tail) {
            return;
        }
        ListNode* mid = getMid(head), *second = mid->next;
        // 切断
        mid->next = nullptr;
        dfs(head, mid);
        dfs(second, tail);

        ListNode* dumy = new ListNode(0, head), *cur = dumy;
        while (head && second) {
            if (head->val < second->val) {
                cur->next = head;
                head = head->next;
            } else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }
        if(head) {
            cur->next = head;
        }
        if (second) {
            cur->next = second;
        }
        head = dumy->next;
    }

    ListNode* getTail(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        while (head->next) {
            head = head->next;
        }
        return head;
    }

    ListNode* getMid(ListNode* head) {
        // 快慢指针获取mid
        ListNode* dumy = new ListNode(0, head);
        ListNode* fast = dumy, *low = dumy;
        while(fast) {
            fast = fast ->next;
            if (fast) {
                low = low->next;
                fast = fast -> next;
            }
        }
        return low;
    }
};

int main() {
    ListNode* head = new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(1)))); 
    head = Solution().sortList(head);
    while(head) {
        cout << head->val << ", ";
        head = head->next;
    }
    return 0;
}