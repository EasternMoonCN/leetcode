#include "utils/tree.cpp"
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
    bool isSameTree2(TreeNode* p, TreeNode* q) {
        // 两个都为null
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // 两个有且只有一个为null
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // int leftSame = isSameTree2(p->left, q->left);
        // int rightSame = isSameTree2(p->right, q->right);
        // return p->val == q->val && leftSame && rightSame;
        return p->val == q->val && isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
    }

    // 递的时候计算，优化版本
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

    bool dfs(TreeNode* p, TreeNode* q) {
        // 两个都为null
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // 两个有且只有一个为null
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // 递的时候提前结束
        if(!(p->val == q->val)) {
            return false;
        }
        if (!(dfs(p->left, q->left))) {
            return false;
        }
        if (!dfs(p->right, q->right)) {
            return false;
        }

        return true;
    }

    bool isSameTree3(TreeNode* p, TreeNode* q) {
        bool isSame = true;
        dfs3(p, q, isSame);
        return isSame;
    }

    void dfs3(TreeNode* p, TreeNode* q, bool& isSame) {
        // 两个都为null
        if (p == nullptr && q == nullptr) {
            return;
        }
        // 两个有且只有一个为null
        if (p == nullptr || q == nullptr) {
            isSame = false;
            return;
        }

        isSame = isSame && (p->val == q->val);
        dfs3(p->left, q->left, isSame);
        dfs3(p->right, q->right, isSame);
    }
};