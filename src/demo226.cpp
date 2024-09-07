//
// Created by EasternMoon on 2024/7/16.
//

#include "utils/tree.h"
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* head = root;
        stack<TreeNode *> nodeStack;
        while (root || !nodeStack.empty()) {
            while (root) {
                TreeNode* temp = root->left;
                root->left = root->right;
                root->right = temp;

                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top(); nodeStack.pop();
            root = root->right;
        }
        return head;
    }

    /*TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        TreeNode* cur = root;
        while (!nodeQueue.empty()) {
            root = nodeQueue.front(); nodeQueue.pop();
            if (!root) continue;
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            nodeQueue.push(root->left);
            nodeQueue.push(root->right);
        }
        return cur;
    }*/

    /*TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left);
        dfs(root->right);
    }*/
};