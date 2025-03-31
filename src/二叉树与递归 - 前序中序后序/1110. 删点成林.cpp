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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> uset;
        for (int d : to_delete) {
            uset.insert(d);
        }
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> TreeNode* {
            if (!node) {
                return nullptr;
            }

            node->left = dfs(node->left);
            node->right = dfs(node->right);

            if (uset.contains(node->val)) {
                if (node->left) {
                    res.push_back(node->left);
                }
                if (node->right) {
                    res.push_back(node->right);
                }
                return nullptr;
            } else {
                return node;
            }
        };
        if (dfs(root)) {
            res.push_back(root);
        }
        return res;
    }
};