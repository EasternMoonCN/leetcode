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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        int left_val = 0, right_val = 0, cur = root->val;
        if (root->val >= low) {
            left_val = rangeSumBST(root->left, low, high);
        } else {
            cur = 0;
        }
        if (root->val <= high) {
            right_val = rangeSumBST(root->right, low, high);
        } else {
            cur = 0;
        }
        return cur + left_val + right_val;
    }
};