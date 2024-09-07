#include "utils/tree.cpp"


/*
给你二叉搜索树的根节点 root ，
该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。

相邻交换，只有一个不满足
非相邻交换，两个不满足
*/

class Solution {
public:

/*
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stack_node;
        // pre：上次访问节点， q：不满足的节点，p：第一次不满足的前一个访问节点
        TreeNode *p = nullptr, *q = nullptr, *pre = nullptr;
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
            if (pre && pre->val >= root->val)
            {
                q = root;
                // 第一次不满足，记录前指针
                if (!p)
                {
                    p = pre;
                }
                // 第二次找到，无需继续遍历 
                else {
                    break;
                }
                
                
            }
            // 记录上次访问的节点
            pre = root;
            root = root->right;
        }
        
        // 交换pq的值
        swap(p->val, q->val);
        
    }

    */
};
