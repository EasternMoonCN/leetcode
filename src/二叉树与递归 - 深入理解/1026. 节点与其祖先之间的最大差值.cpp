#include "../uitls/common.h"
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* node, int max_ele, int min_ele) -> void {
            if (!node) {
                ans = max(ans, max_ele - min_ele);
                return;
            }
            max_ele = max(max_ele, node->val);
            min_ele = min(min_ele, node->val);
            dfs(node->left, max_ele, min_ele);
            dfs(node->right, max_ele, min_ele);
        };
        dfs(root, INT_MIN, INT_MAX);
        return ans;
    }
};