#include "utils/tree.cpp"

class Solution {
public:
    // 如何记录答案？如何知道当前节点是否需要记录
    // 先遍历右子树，再遍历左子树，第一次遍历每一层时需要记录
    // 数组的长度 等于 遍历层次时，说明此层还未记录，需要加到结果中。
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nums;
        dfs(root, nums, 0);
        return nums;
    }
    
    void dfs(TreeNode* root, vector<int>& nums, int level) {
        if (!root) {
            return;
        }

        if (level == nums.size()) {
            nums.push_back(root->val);
        }

        dfs(root->right, nums, level + 1);
        dfs(root->left, nums, level + 1);
    }


};

int main() {
    string s= "";
    
}