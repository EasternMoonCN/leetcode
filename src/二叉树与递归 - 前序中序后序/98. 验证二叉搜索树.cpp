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
    bool isValidBST(TreeNode* root) {
        // auto dfs = [&] (this auto&& dfs, TreeNode* node, long long min_ele, long long max_ele) {
        //     if (!node) {
        //         return true;
        //     }
        //     return node->val > min_ele && node->val < max_ele &&
        //     dfs(node->left, min_ele, min(max_ele, (long long) node->val)) &&
        //     dfs(node->right, max(min_ele, (long long) node->val), max_ele);

        // };
        // return dfs(root, LLONG_MIN, LLONG_MAX);

        // auto dfs = [&] (this auto&& dfs, TreeNode* node, long long min_ele, long long max_ele) {
        //     if (!node) {
        //         return true;
        //     }

        //     if (!dfs(node->left, min_ele, node->val)) {
        //         return false;
        //     }
        //     if (!dfs(node->right, node->val, max_ele)) {
        //         return false;
        //     }
        //     return node->val > min_ele && node->val < max_ele;
        // };
        // return dfs(root, LLONG_MIN, LLONG_MAX);

        auto dfs = [&] (this auto&& dfs, TreeNode* node) -> pair<long long, long long> {
            if (!node) {
                return {LLONG_MAX, LLONG_MIN};
            }

            auto [l_min, l_max] = dfs(node->left);
            auto [r_min, r_max] = dfs(node->right);
            long long x = node->val;
            if (x > l_max && x < r_min) {
                return {min(l_min, x), max(r_max, x)};
            } else {
                return {LLONG_MIN, LLONG_MAX};
            }
        };
        return dfs(root).second != LLONG_MAX;
    }
};