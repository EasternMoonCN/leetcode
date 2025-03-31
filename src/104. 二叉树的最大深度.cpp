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

/**
 * 不要陷入二叉树的细节
 * 原问题最大深度 = max（左子树最大深度， 右子树最大深度） + 1
 * 
 * 原问题：计算整颗树的最大深度
 * 子问题：计算左/右子树的最大深度
 * 原问题和子问题拥有相同的计算方法，但子问题需要吧计算的结果返回给原问题，适合用递归实现。
 * 
 * 由于子问题规模比原问题小，不断（递）下去，总有尽头，即递归的边界条件，直接返回它的答案（归）
 */
class Solution {
public:

    int maxDepth2(TreeNode* root) {
        // 边界条件
        if (!root) {
            return 0;
        }

        // 递：不断分解原问题为子问题，子问题吧计算结果返回给原问题;
        int leftHeight = maxDepth2(root->left);
        int rightHeigt = maxDepth2(root->right);
        
        // 归
        return max(leftHeight, rightHeigt) + 1;
    }

    
    int maxDepth(TreeNode* root) {
        int result = 0;
        dfs(root, 0, result);
        return result;
    }

    void dfs(TreeNode* root, int depth, int& result) {
        // 边界条件
        if (!root) {
            return;
        }
        // 当前层遍历的深度
        depth++;

        // 记录目前遍历节点的深度
        result = max(depth, result);

        // 递：将当前层传给了子树，不想要返回子问题计算结果，递的时候就已经计算出了结果
        dfs(root->left, depth, result);
        dfs(root->right, depth, result);

        // 无需再计算归
    }

    
};