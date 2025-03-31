/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //     if (!root1 && !root2) {
    //         return nullptr;
    //     }

    //     if (!root1) {
    //         return root2;
    //     } 
    //     if (!root2) {
    //         return root1;
    //     }

    //     // 此时root1 root2非空
    //     root1->val += root2->val;

    //     if (root2->left) {
    //         if (!root1->left) {
    //             root1->left = root2->left;
    //         } else {
    //             mergeTrees(root1->left, root2->left);
    //         }
            
    //     }

    //     if (root2->right) {
    //         if (!root1->right) {
    //             root1->right = root2->right;
    //         } else {
    //             mergeTrees(root1->right, root2->right);
    //         }
            
    //     }
    //     return root1;
    // }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }

        if (!root1) {
            return root2;
        } 
        if (!root2) {
            return root1;
        }
        
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        root1->val += root2->val;
        return root1;
    }
};