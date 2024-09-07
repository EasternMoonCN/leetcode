#include "utils/tree.cpp"

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> nums;
        if (!root)
        {
            return nums;
        }
        queue<TreeNode *> queue_node;
        queue_node.push(root);
        int level = -1;
        while (!queue_node.empty())
        {
            vector<int> num;
            int currentLevelNum = queue_node.size();
            ++level;
            for (int i = 0; i < currentLevelNum; i++)
            {
                auto node = queue_node.front();
                num.push_back(node->val);
                queue_node.pop();
                if (level % 2)
                {
                    if (node->left)
                    {
                        queue_node.push(node->left);
                    }
                    if (node->right)
                    {
                        queue_node.push(node->right);
                    }
                }
                else
                {
                    if (node->right)
                    {
                        queue_node.push(node->right);
                    }
                    if (node->left)
                    {
                        queue_node.push(node->left);
                    }
                }
            }
            nums.push_back(num);
        }
        return nums;
    }
};

int main() {

    TreeNode* root = tree().createTreeNodeFromLevelOrder({1, 2, 3, 4, 5});
    vector<vector<int>> nums = Solution().zigzagLevelOrder(root);
    common<int>().printVectors(nums);
}