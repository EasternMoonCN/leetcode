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
    // int goodNodes(TreeNode* root) {
    //     auto dfs = [](this auto&& dfs, TreeNode* root, int max_ele) -> int {
    //         if (!root) {
    //             return 0;
    //         }
    //         max_ele = max(root->val, max_ele);
    //         return dfs(root->left, max_ele) + dfs(root->right, max_ele) + (root->val >= max_ele);
    //     };
    //     return dfs(root, INT_MIN);
    // }
    int goodNodes(TreeNode* root) {
        auto dfs = [](this auto&& dfs, TreeNode* root, int max_ele, int& res) -> void {
            if (!root) {
                return;
            }
            max_ele = max(root->val, max_ele);
            res += root->val >= max_ele;
            dfs(root->left, max_ele, res);
            dfs(root->right, max_ele, res);
        };
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};