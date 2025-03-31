#include "utils/tree.cpp"

class Solution {
public:
    // bool isSymmetric2(TreeNode* root) {
    //     return dfs2(root->left, root->right);
    // }

    // 判断pq是否是轴对称
    bool dfs2(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }
        // 判断左边子树和右边子树是否相同，右边子树和左边子树是否相同
        return p->val == q->val && dfs2(p->left, q->right) && dfs2(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }

        if (p->val != q->val) {
            return false;
        }

        if (!dfs(p->left, q->right)) {
            return false;
        }

        if (!dfs(p->right, q->left)) {
            return false;
        }

        return true;
    }
};