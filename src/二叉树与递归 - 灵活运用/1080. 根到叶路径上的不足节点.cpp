/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // TreeNode* sufficientSubset(TreeNode* root, int limit) {
    //     auto dfs = [&](this auto && dfs, TreeNode* node, int val) ->
    //     TreeNode* {
    //         if (!node) {
    //             return nullptr;
    //         }
    //         val += node->val;
    //          // 记录是否最后一个
    //         int last = false;
    //         if (!node->left && !node->right) {
    //             last = true;
    //         }
    //         node->left = dfs(node->left, val);
    //         node->right = dfs(node->right, val);
    //         if (!node->left && !node->right) {
    //             return !last || val < limit ? nullptr : node;
    //         } else {
    //             return node;
    //         }
    //     };
    //     return dfs(root, 0);
    // }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) {
            return nullptr;
        }
        limit -= root->val;
        // root是叶子节点
        if (!root->left && !root->right) {
            return limit > 0 ? nullptr : root;
        }
        // root非叶子节点
        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);
        return !root->left && !root->right ? nullptr : root;
    }
};