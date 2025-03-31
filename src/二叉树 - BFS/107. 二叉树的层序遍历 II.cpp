#include "../utils/tree.h"
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> qnode;
        qnode.push(root);
        
        while (!qnode.empty()) {
            int size = qnode.size();
            vector<int> num;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qnode.front(); qnode.pop();
                num.push_back(node->val);
                if (node->left) qnode.push(node->left);
                if (node->right) qnode.push(node->right);
            }
            res.push_back(num);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};