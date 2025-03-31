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
    // int minDepth(TreeNode* root) {
    //     auto dfs = [](this auto&& dfs, TreeNode* root, int depth, int& result) -> void {
    //         if (!root) {
    //             return;
    //         }
    //         if (!root->left && !root->right) {
    //             result = min(result, depth + 1);
    //         }
    //         dfs(root->left, depth + 1, result);
    //         dfs(root->right, depth + 1, result);
    //     };
    //     int result = INT_MAX;
    //     dfs(root, 0, result);
    //     return result == INT_MAX ? 0 : result;
    // }

    // 只有在左右子树为空时，才能求最小值
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l_depth = minDepth(root->left);
        int r_depth = minDepth(root->right);

        if (root->left && root->right) {
            return min(l_depth, r_depth) + 1;
        }
        if(root->left) {
            return l_depth + 1;
        }
        if(root->right) {
            return r_depth + 1;
        }
        return 1;
    }
};/**
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
    // int minDepth(TreeNode* root) {
    //     auto dfs = [](this auto&& dfs, TreeNode* root, int depth, int& result) -> void {
    //         if (!root) {
    //             return;
    //         }
    //         if (!root->left && !root->right) {
    //             result = min(result, depth + 1);
    //         }
    //         dfs(root->left, depth + 1, result);
    //         dfs(root->right, depth + 1, result);
    //     };
    //     int result = INT_MAX;
    //     dfs(root, 0, result);
    //     return result == INT_MAX ? 0 : result;
    // }

    // 只有在左右子树为空时，才能求最小值
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l_depth = minDepth(root->left);
        int r_depth = minDepth(root->right);

        if (root->left && root->right) {
            return min(l_depth, r_depth) + 1;
        }
        if(root->left) {
            return l_depth + 1;
        }
        if(root->right) {
            return r_depth + 1;
        }
        return 1;
    }
};