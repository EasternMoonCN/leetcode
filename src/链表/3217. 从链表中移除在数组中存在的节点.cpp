
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> iset(nums.begin(), nums.end());

        ListNode dummy(0, head);
        auto cur = &dummy;
        while (cur->next) {
            auto next = cur->next;
            if (iset.count(next->val)) {
                cur->next = next->next;
                // delete next;
            } else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};