#include "./utils/tree.cpp"

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> nums;
        if (!root)
        {
            return nums;
        }
        
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        
        nums.push_back(root->val);
        while (!node_queue.empty())
        {
            bool flag = true;
            int size = node_queue.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = node_queue.front();
                node_queue.pop();
                if (cur->right)
                {
                    node_queue.push(cur->right);
                    if (flag)
                    {
                        nums.push_back(cur->right->val);
                        flag = false;
                    }
                    
                }
                if (cur->left)
                {
                    node_queue.push(cur->left);
                    if (flag)
                    {
                        nums.push_back(cur->left->val);
                        flag = false;
                    }
                }
            }
        }
        return nums;
    }
};

int main() {
    TreeNode* root = tree().createTreeNodeFromLevelOrder({1, 2, 3, INT_MAX, 5, INT_MAX, 4});
    vector<int> nums = Solution().rightSideView(root);
    common<int>().printVector(nums);
}