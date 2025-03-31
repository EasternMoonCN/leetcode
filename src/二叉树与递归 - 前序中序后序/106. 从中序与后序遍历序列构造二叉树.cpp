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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> umap;
        for (int i = 0; i < inorder.size(); ++i) {
            umap[inorder[i]] = i;
        }
        auto dfs = [&](this auto&& dfs, int left, int right, int postIndex) -> TreeNode* {
            if (left > right) {
                return nullptr;
            }

            TreeNode* root = new TreeNode(postorder[postIndex]);
            int inIndex = umap[postorder[postIndex]];
            int rightSize = right - inIndex;
            root->left = dfs(left, inIndex - 1, postIndex - rightSize - 1);
            root->right = dfs(inIndex + 1, right, postIndex - 1);
            return root;
        };
        return dfs(0, inorder.size() - 1, postorder.size() - 1);
    }
};