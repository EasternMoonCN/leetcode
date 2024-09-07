#include "utils/tree.cpp"

/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
    5
  4   6
     3  7
*/
class Solution {
public:

    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*> stack_node;
        long long pre_num = LONG_MIN;
        while (!stack_node.empty() || root)
        {
            while (root)
            {
                stack_node.push(root);
                root = root->left;
            }

            root = stack_node.top();
            stack_node.pop();
            // 中序遍历中：上一次访问的值是否小于当前访问的值
            if (pre_num >= root->val)
            {
                // 不满足则直接返回false
                return false;
            }
            // 满足则记录访问值为上次一访问值
            pre_num = root->val;
            
            root = root->right;
        }
        
        return true;
    }

    /*
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    */

    /*
        判断以root为根节点的子树，所有节点值是否属于lower，upper
    */
    bool dfs(TreeNode* root, long long lower, long long upper) {
        if (!root)
        {
            return true;
        }

        if (root->val >= upper || root->val <= lower)
        {
            return false;
        }
        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
        
    }
};

