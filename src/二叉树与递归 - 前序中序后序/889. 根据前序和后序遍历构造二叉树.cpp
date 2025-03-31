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
    // int getLeftSize (vector<int>& preorder, vector<int>& postorder, int preLeft, int preRight, int postLeft, int postRight) {
    //     int c = 0;
    //     cout << preLeft << "," << preRight << "," << postLeft << "," << postRight << endl;
    //     for (int i = 0; i < preRight - preLeft + 1; ++i) {
    //         c ^= (1 << preorder[preLeft + i]);
    //         c ^= (1 << postorder[postLeft + i]);
    //         if (!c) {
    //             return i + 1;
    //         }
    //     }
    //     return 0;
    // }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> umap;
        for (int i = 0; i < postorder.size(); ++i) {
            umap[postorder[i]] = i;
        }

        auto dfs = [&](this auto && dfs, int preLeft, int preRight, int postLeft, int postRight) -> TreeNode* {
            if (preLeft > preRight) {
                return nullptr;
            }
            if (preLeft == preRight) {
                return new TreeNode(preorder[preLeft]);
            }
            // 认定preLeft+1属于左子树根节点
            int leftSize = umap[preorder[preLeft + 1]] - postLeft + 1;
            int rightSize = preRight - preLeft - leftSize;
            auto left = dfs(preLeft + 1, preLeft + leftSize, postLeft, postRight - rightSize - 1);
            auto right = dfs(preLeft + leftSize + 1, preRight, postRight - rightSize, postRight - 1);
            return new TreeNode(preorder[preLeft], left, right);
        };
        return dfs(0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};