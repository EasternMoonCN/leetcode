#include "utils/tree.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) >= 0;
    }
    // 子树高度，节点非平衡时返回-1
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left);
        if (l < 0) {
            return -1;
        }
        int r = dfs(root->right);
        if (r < 0) {
            return -1;
        }
        return abs(l - r) <= 1 ? 1 + max(l, r) : -1;
    }


    bool isBalanced2(TreeNode* root) {
        if (!root) {
            return true;
        }
        int leftHeight = getHeight2(root->left);
        int rightHeight = getHeight2(root->right);
        return abs(leftHeight - rightHeight) <= 1 && isBalanced2(root->left) && isBalanced2(root->right);
    }

    int getHeight2(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = getHeight2(root->left);
        int rightHeight = getHeight2(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
};