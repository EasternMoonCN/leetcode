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
    int res = 0;

    tuple<int, int, int> sumBST(TreeNode* root) {
         if (!root) {
            return {INT_MAX, INT_MIN, 0};
        }
        auto [l_min, l_max, lsum] = sumBST(root->left);
        auto [r_min, r_max, rsum] = sumBST(root->right);
        int s = root->val + lsum + rsum;
        // 是一个搜索树
        if (root->val > l_max && root->val < r_min) {
            res = max(res, s);
            return {min(l_min, root->val), max(r_max, root->val), s};
        }
        return {INT_MIN, INT_MAX, s};
    }

    int maxSumBST(TreeNode* root) {
       sumBST(root);
       return res;
    }
};