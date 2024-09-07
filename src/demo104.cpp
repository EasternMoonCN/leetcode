//
// Created by EasternMoon on 2024/7/16.
//
#include "utils/tree.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int> > nodeQueue;
        int level = 1;
        nodeQueue.push(make_pair(root, level));
        while (!nodeQueue.empty()) {
            auto nodePair = nodeQueue.front();
            nodeQueue.pop();
            level = nodePair.second;
            if (nodePair.first->left) {
                nodeQueue.push(make_pair(nodePair.first->left, nodePair.second + 1));
            }
            if (nodePair.first->right) {
                nodeQueue.push(make_pair(nodePair.first->right, nodePair.second + 1));
            }
        }
        return level;
    }
    /*int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int> > nodeStack;
        int maxResult = 0, curLevel = 1;
        while (root || !nodeStack.empty()) {
            while (root) {
                maxResult = max(curLevel, maxResult);
                nodeStack.push(make_pair(root, curLevel));
                root = root->left;
                ++curLevel;
            }
            pair<TreeNode*, int> nodePair = nodeStack.top();
            nodeStack.pop();
            root = nodePair.first->right;
            curLevel = nodePair.second + 1;
        }
        return maxResult;
    }*/
    /*int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }*/


};

int main() {
    TreeNode n3 = TreeNode(3);
    TreeNode n9 = TreeNode(9);
    TreeNode n20 = TreeNode(20);
    TreeNode n15 = TreeNode(15);
    TreeNode n7 = TreeNode(7);
    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;

    cout << Solution().maxDepth(&n3);
}