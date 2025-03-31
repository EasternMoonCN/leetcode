#include "utils/tree.cpp"

class Solution {
public:
    // 分别求每个节点左右高度，返回当前左右节点高度只和 或 左右子树 中最大值
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHegiht = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return max(leftHegiht + rightHeight, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    // 求取节点root的高度
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};