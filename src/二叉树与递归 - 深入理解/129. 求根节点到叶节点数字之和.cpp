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
    // int sumNumbers(TreeNode* root) {
    //     auto dfs = [](this auto&& dfs, TreeNode* root, int res) -> int {
    //         if (!root) {
    //             return 0;
    //         }
    //         res = res * 10 + root->val; 
    //         if(!root->left && !root->right) {
    //             return res;
    //         }
    //         return dfs(root->left, res) + dfs(root->right, res);
    //     };

    //     return dfs(root, 0);
    // }

    int sumNumbers(TreeNode* root) {
        auto dfs = [](this auto&& dfs, TreeNode* root, int num, int& res) ->void {
            if (!root) {
                return;
            }
            num = num * 10 + root->val;
            if(!root->left && !root->right) {
                res += num;
                return;
            }
            dfs(root->left, num, res);
            dfs(root->right, num, res);
        };
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};