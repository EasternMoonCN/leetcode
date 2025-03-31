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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) {
            return root;
        } else {
            root->val = 0;
        }
        queue<TreeNode*> qnode1, qnode2;
        qnode1.push(root);
        while (!qnode1.empty()) {
            int size = qnode1.size();
            int nextLvlSum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = qnode1.front(); qnode1.pop();
                qnode2.push(node);
                if (node->left) {
                    nextLvlSum += node->left->val;
                    qnode1.push(node->left);
                }
                if (node->right) {
                    nextLvlSum += node->right->val;
                    qnode1.push(node->right);
                }
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* node = qnode2.front(); qnode2.pop();
                int val = nextLvlSum;
                if (node->left) {
                    val -= node->left->val;
                }
                if (node->right) {
                    val -= node->right->val;
                    node->right->val = val;
                }
                if(node->left) {
                    node->left->val = val;
                }
            }

        }
        return root;
    }
};