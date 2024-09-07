#include "utils/tree.cpp"

/*
先序遍历： 根节点 左子树 右子树
中序遍历： 左子树 根节点 右子树

查找先序遍历中，根节点在中序遍历中的下标，即可确认左子树，右子树个数
*/
class Solution
{
public:
    // 中序遍历第一个节点表示，没有可访问的左节点了
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        stack<TreeNode *> stack_node;
        TreeNode *root = new TreeNode(preorder[0]), *node;
        stack_node.push(root);
        int inorder_index = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            node = stack_node.top();
            if (node->val != inorder[inorder_index])
            {
                node->left = new TreeNode(preorder[i]);
                node = node->left;
                stack_node.push(node);
            }
            else
            {
                while (!stack_node.empty() && node->val == inorder[inorder_index])
                {
                    node = stack_node.top();
                    stack_node.pop();
                    ++inorder_index;
                }
                node->right = new TreeNode(preorder[i]);
                stack_node.push(node->right);
            }
        }

        return root;
    }

    // preorderIndex 先序遍历中根节点位置，inorderLeft 中序遍历左边界， inorderRight 中序遍历右边界
    // [inorderLeft, inorderRight)
    TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int preorderIndex, int inorderLeft, int inorderRight)
    {
        if (inorderLeft >= inorderRight)
        {
            return nullptr;
        }

        // 根节点在中序遍历中下标
        int inorderIndex = inorderMap[preorder[preorderIndex]];
        TreeNode *root = new TreeNode(preorder[preorderIndex]);
        // 左子树个数：inorderIndex - inorderLeft, 右子树个数：inorderRight - inorderIndex + 1
        root->left = dfs(preorder, inorderMap, preorderIndex + 1, inorderLeft, inorderIndex);
        root->right = dfs(preorder, inorderMap, preorderIndex + inorderIndex - inorderLeft + 1, inorderIndex + 1, inorderRight);
        return root;
    }

    /*
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            // 缓存value->索引
            unordered_map<int, int> inorderMap;
            for (int i = 0; i < inorder.size(); ++i)
            {
                inorderMap[inorder[i]] = i;
            }
            return dfs(preorder, inorderMap, 0, 0, inorder.size());
        }
        */
};