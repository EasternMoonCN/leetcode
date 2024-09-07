//
// Created by EasternMoon on 2024/7/6.
//

#include "utils/link.h"
class Solution{
public:
    vector<int> reverseNumber(vector<int> nums) {
        vector<int> result;
        dfs(nums, result, 0);
        return result;
    }

    void dfs(vector<int>& nums, vector<int>& result, int i) {
        if (i == nums.size()) {
            return;
        }
        result.push_back(nums[i]);
        dfs(nums, result, i + 1);
//        result.push_back(nums[i]);
    }

    ListNode* stackReverse(ListNode* head) {
        stack<ListNode*> linkStack;
        while (head) {
            linkStack.emplace(head);
            head = head->next;
        }
        ListNode* node = linkStack.top(); linkStack.pop();
        head = node;
        while (!linkStack.empty()) {
            node->next = linkStack.top();
            linkStack.pop();
            node = node->next;
        }
        node->next = nullptr;
        return head;
    }

    ListNode* reverseLink(ListNode* head) {
        return dfs(nullptr, head);
    }

    ListNode* dfs(ListNode* pre, ListNode* cur) {
        if (!cur) {
            return pre;
        }
        ListNode* next = cur->next;
        cur->next = pre;
        return dfs(cur, next);
    }
};

int main() {
//    vector<int> nums = {1, 2, 3, 4, 5};
//    vector<int> result = Solution().reverseNumber(nums);
//    common::printVector(result);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;
    ListNode* head = Solution().stackReverse(&n1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}