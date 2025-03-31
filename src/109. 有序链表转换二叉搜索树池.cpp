#include "utils/common.cpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, nullptr);
    }

    // 生成平衡二叉树[left, right)
    TreeNode* dfs(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        } 
        // 求出的中间元素，可能与left一致
        ListNode* mid = getMid(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = dfs(left, mid);
        root->right = dfs(mid->next, right);
        return root;
    }

    // 快慢指针获取中间元素 [left, right)
    ListNode* getMid(ListNode* left, ListNode* right) {
        ListNode* fast = left, *slow = left;
         while (fast != right && fast->next != right) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    ListNode* l1 = new ListNode(-10);
    ListNode* l2 = new ListNode(-3);
    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(9);

    l1->next=l2;l2->next = l3; l3->next = l4; l4->next=l5;
    TreeNode* root = Solution().sortedListToBST(l1);
    cout << root->val << endl;
}