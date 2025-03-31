#include "../utils/tree.h"
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qnode;
        qnode.push(root);
        TreeNode* node;
        while (!qnode.empty()) {
            int size = qnode.size();
            for (int i = 0; i < size; ++i) {
                node = qnode.front(); qnode.pop();
                if (node->right) {
                    qnode.push(node->right);
                }
                if (node->left) {
                    qnode.push(node->left);
                }
                
            }
        }
        return node->val;
    }
};