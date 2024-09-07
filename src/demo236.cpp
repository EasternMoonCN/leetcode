#include "./utils/tree.cpp"

/**
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
 *      满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 */
class Solution
{
private:
    TreeNode *ans;

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }

    /**
     *  判断当前节点root及其子树 是否包含 p 或 q
     */
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root)
        {
            return false;
        }

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 当前节点 的 左子树且右子树分别包含pq 或
        // 当前节点 的 左子树且右子树仅包含p或q 且 当前节点为p或q
        if ((lson && rson) || ((lson || rson) && (root->val == p->val || root->val == q->val)))
        {
            // 记录祖节点
            ans = root;
        }
        return lson || rson || root->val == p->val || root->val == q->val;
    }
};

int main()
{
    vector<int> nums = {3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4};
    TreeNode *root = tree().createTreeNodeFromLevelOrder(nums);
    TreeNode *p = new TreeNode(5), *q = new TreeNode(1);
    cout << Solution().lowestCommonAncestor(root, p, q)->val;
    delete p, q;
    return 0;
}