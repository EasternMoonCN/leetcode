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
    // 归
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) {
    //         return nullptr;
    //     }
    //     TreeNode* left = root->left;
    //     root->left = invertTree(root->right);
    //     root->right = invertTree(left);
    //     return root;
    // }

    // 递
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) {
    //         return nullptr;
    //     }
    //     TreeNode* r1 = new TreeNode(root->val);
    //     dfs(root, r1);
    //     return r1;
    // }

    // void dfs(TreeNode* p, TreeNode* q) {
    //     if (!p->left && !p->right) {
    //         return;
    //     }
    //     if (p->left) {
    //         q->right = new TreeNode(p->left->val);
    //         dfs(p->left, q->right);
    //     }
    //     if (p->right) {
    //         q->left = new TreeNode(p->right->val);
    //         dfs(p->right, q->left);
    //     }

    // }
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) {
    //         return nullptr;
    //     }
    //     invertTree(root->left, root->right);
    //     return root;
    // }

    // void invertTree(TreeNode* p, TreeNode* q) {
    //     if (!p && !q) {
    //         return;
    //     }
    //     if (p && q) {
    //         swap(p->val, q->val);
    //     } else if (p) {

    //     } else {

    //     }
        
    //     invertTree(p->left, q->right);
    //     invertTree(p->right, q->left);
    // }
};