//
// Created by EasternMoon on 2024/7/20.
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode* cur = root;
        TreeNode* dummy = new TreeNode(), *temp = dummy;
        while(!nodeStack.empty() || cur) {
            while(cur) {
                temp->right = new TreeNode(cur->val);
                temp = temp->right;
                nodeStack.push(cur);
                cur = cur->left;
            }
            cur = nodeStack.top(); nodeStack.pop();
            cur = cur->right;
        }
        root = dummy->right;
        delete dummy;
    }
};
int main() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4;
    Solution().flatten(&n1);
    cout << &n1;
}