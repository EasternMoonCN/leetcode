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
    // int maxDepth(TreeNode* root) {
    //     if (!root) {
    //         return 0;
    //     }
    //     return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    // }
    int maxDepth(TreeNode* root) {
        auto dfs = [](this auto&& dfs, TreeNode* root, int depth, int& result) -> void {
            if (!root) {
                return;
            }
            result = max(result, depth + 1);
            dfs(root->left, depth + 1, result);
            dfs(root->right, depth + 1, result);
        };
        int result = 0;
        dfs(root, 0, result);
        return result;
    }
};