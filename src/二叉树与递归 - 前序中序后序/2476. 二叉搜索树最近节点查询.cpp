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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        auto inorder = [&](this auto&& inorder, TreeNode* node) {
            if (!node) {
                return;
            }
            inorder(node->left);
            nums.push_back(node->val);
            inorder(node->right);
        };

        inorder(root);

        int n = queries.size();
        vector<vector<int>> res(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int i1;
            auto m1 = upper_bound(nums.begin(), nums.end(), queries[i]);
            if (m1 == nums.begin()) {
                i1 = -1;
            } else {
                i1 = *(m1 - 1);
            }
            auto m2 = lower_bound(nums.begin(), nums.end(), queries[i]);
            int i2;
            if (m2 == nums.end()) {
                i2 = -1;
            } else {
                i2 = *m2;
            }
            res[i] = {i1, i2};
        }
        return res;
    }
};