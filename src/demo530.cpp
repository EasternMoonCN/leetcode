#include "utils/tree.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        return inorder(root);
    }

    int inorder(TreeNode* root) {
        stack<TreeNode*> node;
        vector<int> nums;
        int res = INT_MAX;
        while (root || !node.empty()) {
            while (root) {
                node.push(root);
                root = root->left;
            }
            root = node.top();
            node.pop();
            nums.push_back(root->val);
            if (nums.size() > 1 && res > abs(nums[nums.size() -2] - nums[nums.size() - 1])) {
                res = abs(nums[nums.size() -2] - nums[nums.size() - 1]);
            }
            root = root->right;
        }
        return res;
    }
};