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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> pair<int, TreeNode*> {
            if (!node) {
                return {0, nullptr};
            }
            auto [ldepth, left] = dfs(node->left);
            auto [rdepth, right] = dfs(node->right);

            if (ldepth == rdepth) {
                return {ldepth + 1, node};
            }

            if (ldepth > rdepth) {
                return {ldepth + 1, left};
            } else {
                return {rdepth + 1, right};
            }
        };
        return dfs(root).second;
    }
    // int maxDepth = -1;
    // TreeNode* ans;
    // TreeNode* lcaDeepestLeaves(TreeNode* root) {
    //     auto dfs = [&](this auto&& dfs, TreeNode* node, int depth = 0) -> int {
    //         if (!node) {
    //             maxDepth = max(depth, maxDepth);
    //             return depth;
    //         }
    //         int leftDepth = dfs(node->left, depth + 1);
    //         int rightDepth = dfs(node->right, depth + 1);
    //         if (leftDepth == rightDepth && maxDepth == leftDepth) {
    //             ans = node;
    //         }
    //         return max(leftDepth, rightDepth);
    //     };
    //     dfs(root);
    //     return ans;
    // }

    // TreeNode* lcaDeepestLeaves(TreeNode* root) {
    //     int maxDepth = -1;
    //     auto dfs = [&](this auto&& dfs, TreeNode* node, int depth = 0) ->
    //     pair<int, TreeNode*> {
    //         if (!node) {
    //             return {depth, nullptr};
    //         }
    //         if (!node->left && !node->right) {
    //             if (depth >= maxDepth) {
    //                 maxDepth = depth;
    //                 return {depth, node};
    //             }
    //             return {depth, nullptr};
    //         }
    //         auto [ldepth, left] = dfs(node->left, depth + 1);
    //         auto [rdepth, right] = dfs(node->right, depth + 1);
    //         // 返回公共祖先
    //         if (left && right && maxDepth == ldepth && maxDepth == rdepth) {
    //             return {maxDepth, node};
    //         }
    //         // 仅左子树生效
    //         if (left && maxDepth == ldepth) {
    //             return {maxDepth, left};
    //         }
    //         // 仅右子树生效
    //         if (right && maxDepth == rdepth) {
    //             return {maxDepth, right};
    //         }

    //         return {depth, nullptr};
    //     };
    //     auto res = dfs(root);
    //     return res.second;
    // };
};