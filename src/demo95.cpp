#include "utils/tree.cpp"

/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
*/

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n < 1)
        {
            return {};
        }
        
        return backtrack(1, n);
    }

    /*
        以start为开始节点，end为结束节点，生成的所有子树
    */
    vector<TreeNode *> backtrack(int start, int end)
    {
        vector<TreeNode *> nums;

        /*需为空节点，否则不会遍历*/
        if (start > end)
        {
            return {nullptr};
        }
        /*
            遍历以i为根节点
        */
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> lefts = backtrack(start, i - 1);
            vector<TreeNode *> rights = backtrack(i + 1, end);

            /*
                以i为根节点，lefts为左子树集合，rights为右子树集成生成所有树
            */
            for (TreeNode *left : lefts)
            {
                for (TreeNode* right : rights)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    nums.push_back(root);
                }
                
            }
        }
        return nums;
    }
};