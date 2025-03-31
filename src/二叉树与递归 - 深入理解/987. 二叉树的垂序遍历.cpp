#include "../utils/tree.cpp"

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int min_col = 0, max_col = 0;
        // unordered_map<TreeNode*, pair<int, int>> umap;
        unordered_map<int, vector<pair<int, TreeNode*>>> umap;

        auto dfs = [&](auto&& dfs, TreeNode* node, int row, int col) -> void {
            if (!node) {
                return;
            }
            min_col = min(min_col, col);
            max_col = max(max_col, col);
            // umap.insert(node, {row, col});
            // umap.insert(col, {row, node});
   
            umap[col].push_back(make_pair(row, node));
            
            dfs(dfs, node->left, row + 1, col - 1);
            dfs(dfs, node->right, row + 1, col + 1);
        };
        
        dfs(dfs, root, 0, 0);
        vector<vector<int>> res(max_col - min_col + 1);
        for (int i = 0; i < res.size(); ++i) {
            vector<pair<int, TreeNode*>> nodes = umap[i + min_col];
            sort(nodes.begin(), nodes.end(), [](auto n1, auto n2) {
                if (n1.first == n2.first) {
                    return n1.second->val <= n2.second->val;
                }
                return n1.first < n2.first;
            });
            for (auto node : nodes) {
                res[i].push_back(node.second->val);
            }
        }
        return res;
    }
};

int main() {
    TreeNode* node = tree().createTreeNodeFromLevelOrder({3, 9, 20, INT_MAX, INT_MAX, 15, 7});
    vector<vector<int>> res = Solution().verticalTraversal(node);
    common<int>::printVectors(res);
}