//
// Created by EasternMoon on 2024/7/21.
//
#include "utils/head.h"
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        vector<int> nums = orderTraversal(root);
        return maxNumSum(nums);
    }

    int maxNumSum(const vector<int>& nums) {
        // dp[i]: 以第 i 个数结尾的「连续子数组的最大和」
        vector<int> dp = vector<int>(nums.size(), 0);
        dp[0] = nums[0];
        int maxNum = dp[0];
        for(int i = 1; i < dp.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxNum = max(maxNum, dp[i]);
        }
        return maxNum;

    }

    vector<int> orderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack = stack<TreeNode*>();
        vector<int> nums = vector<int>();
        while(!nodeStack.empty() || root) {
            while(root) {
                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top(); nodeStack.pop();
            nums.push_back(root->val);
            root = root->right;
        }
        return nums;
    }
};
/*
 *    5
 *  4 -1
 * 7 8
 */

int main() {
    vector<int> nums = {1, -2, -3, 1, 3, -2, INT_MAX, -1};
    TreeNode* root = tree().createTreeNodeFromLevelOrder(nums);
    cout << Solution().maxPathSum(root);
    return 0;
}