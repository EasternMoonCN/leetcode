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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {

            // 减去本节点
            return targetSum  == root->val;
        }
        if (hasPathSum(root->left, targetSum - root->val)) {
            return true;
        }
        if (hasPathSum(root->right, targetSum - root->val)) {
            return true;
        }
        return false;
    }

    // 无法判断返回结果取哪一个
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     auto dfs = [](TreeNode* root) -> int {
    //         if (!root) {
    //             return 0;
    //         }
    //     }
    // }
};