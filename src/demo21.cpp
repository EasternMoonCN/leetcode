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
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
  
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(), *r = dummy, *p = list1, *q = list2;
        while(p != nullptr && q != nullptr) {
            if (p->val < q->val)
            {
                r -> next = p;
                p = p -> next;
            } else {
                r -> next = q;
                q = q->next;
            }
            r = r -> next;
        }
        if (p != nullptr)
        {
            r -> next = p;
        } else {
            r -> next = q;
        }
        return dummy -> next;
    }
};

int main () {
    ListNode * list1 = new ListNode(1, new ListNode(2, new ListNode(4, nullptr)));
    ListNode * list2 = new ListNode(1, new ListNode(3, new ListNode(4, nullptr)));
    Solution().mergeTwoLists(list1, list2);
}