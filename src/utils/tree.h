//
// Created by EasternMoon on 2024/6/27.
//

#ifndef LEETCODE_TREE_NODE_H
#define LEETCODE_TREE_NODE_H


#include "common.cpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class tree {
public:
    void deleteTree(TreeNode *root);

    vector<int> levelOrder(TreeNode *root);

    /**
 * 层序遍历创建二叉树
 * 1. 将根节点放入队列
 * 2. 遍历队列非空 且 未达到最大序列
 * 3. 遍历根节点，当根节点的左右子节非空，创建左右节点，并放入队列
 * 4. 返回第二步
 */

    TreeNode *createTreeNodeFromLevelOrder(vector<int> nums);

    void inOrderDfs(vector<int> &nums, TreeNode *root);

    void preOrderDfs(vector<int> &nums, TreeNode *root);

    vector<int> preOrderDfs(TreeNode *root);

    vector<int> inOrderDfs(TreeNode *root);

    /**
 * 先序遍历
 * 1. 栈非空 或者 根节点非空时，遍历
 * 2. 访问节点，并遍历左节点，直到左节点为空
 * 3. 访问栈顶元素右节点，并出栈
 */
    vector<int> preorderDfs(TreeNode *root);

    /**
     二叉树中序遍历: 左子树，根节点，右子树
    1. 堆非空 或者 当前遍历节点非空，继续遍历
    2. 当前访问节点非空时，将遍历访问入队，并继续遍历左节点
    3. 没有左子树时，访问节点
    2. 遍历右节点
*/
    vector<int> inorderDfs(TreeNode *root);

    /*
后序遍历：根节点最后访问，即需要左右子树都访问完成
*/
    vector<int> postorderDfs(TreeNode *root);

    vector<int> orderColorDfs(TreeNode *root, string order);

    vector<int> preOrderColorDfs(TreeNode *root);

    vector<int> inOrderColorDfs(TreeNode *root);

    vector<int> postOrderColorDfs(TreeNode *root);
};


#endif //LEETCODE_TREE_NODE_H
