#include "./utils/tree.cpp"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> node;
        node.emplace(root);
        vector<double> nums;
        while (!node.empty())
        {
            auto size = node.size();
            auto sum = 0.;
            for (size_t i = 0; i < size; i++)
            {
                auto cur = node.front(); node.pop();
                sum += cur->val;
                if (cur->left)
                {
                    node.emplace(cur->left);
                }
                if (cur->right) {
                    node.emplace(cur->right);
                }
            }
            nums.emplace_back(sum / size);
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    TreeNode* root = tree().createTreeNodeFromLevelOrder(nums);
    vector<double> results = Solution().averageOfLevels(root);
    common<double>().printVector(results);
}