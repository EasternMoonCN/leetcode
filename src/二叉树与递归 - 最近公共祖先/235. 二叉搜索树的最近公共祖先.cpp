/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     auto dfs = [&](this auto&& dfs, TreeNode* node) -> TreeNode* {
    //         if (!node || node == p || node == q) {
    //             return node;
    //         }

    //         TreeNode* left = dfs(node->left);
    //         TreeNode* right = dfs(node->right);

    //         // 左子树找到了p或q，右子树找到了q或q，则当前节点为祖先
    //         if (left && right) {
    //             return node;
    //         }
    //         // 1. 要么左或右子树已经包含了所有节点
    //         // 2. 要么左或右子树仅包含一个节点，单前节点也不满足
    //         // 3. 要么一个节点也不满足
    //         return left ? left : right;
    //     };
    //     return dfs(root);
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = root->val;
        if (p->val < x && q->val < x) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > x && q->val > x) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};