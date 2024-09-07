#include "utils/tree.cpp"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dps(nums, 0, nums.size() - 1);
    }

    // l:左边界，r右边界
    TreeNode* dps(vector<int>& nums, int l, int r) {
        if (r - l < 0) {
            return nullptr;
        }
        // 中间节点作为根节点
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        // 左子树
        root->left = dps(nums, l, m - 1);
        // 右子树
        root->right = dps(nums, m + 1, r);
        return root;
    }
};