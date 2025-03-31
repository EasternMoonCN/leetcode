#include "utils/common.cpp"

class Solution {
public:

    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    // dp[i + 2] = max(dp[i] + nums[i], dp[i + 1]);
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];

        dp[1][0] = nums[1];
        dp[1][1] = nums[0];

        for (int i = 2; i < n; ++i) {
            dp[i][0] = max(dp[i - 2][0] + nums[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][1] + nums[i], dp[i - 1][1]);
        }
        // 不选第0个（1, i - 1） 不选低n - 1个(0. n - 2)
        return max(dp[n - 1][0], dp[n - 2][1]);
    }

    // vector<vector<int>> cache;
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     cache = vector<vector<int>>(n, vector<int>(2, -1));;
    //     return dfs(n - 1, nums, false);
    // }

    // int dfs(int i, vector<int>& nums, bool flag) {
    //     if (i < 0) {
    //         return 0;
    //     }
    //     if (cache[i][flag] != -1) {
    //         return cache[i][flag];
    //     }

    //     // 偷
    //     int v1 = 0;
    //     if (i == nums.size() - 1) {
    //         v1 = dfs(i - 2, nums, true) + nums[i];
    //     } else {
    //         if (!flag || i != 0) {
    //             v1 = dfs(i - 2, nums, flag) + nums[i];
    //         }
    //     }

    //     // 不偷
    //     int v2 = dfs(i - 1, nums, flag);
    //     cache[i][flag] = max(v1, v2);
    //     return cache[i][flag];
    // }

    // int dfs(int i, vector<int>& nums, bool flag) {
    //     if (i < 0) {
    //         return 0;
    //     }
    //     // 偷
    //     int v1 = 0;
    //     if (!flag || i != 0) {
    //         v1 = dfs(i - 2, nums, i == nums.size() - 1 ? true : flag) +
    //         nums[i];
    //     }
    //     // 不偷
    //     int v2 = dfs(i - 1, nums, flag);
    //     return max(v1, v2);
    // }
};

int main() {
    vector<int> nums = {2, 3, 2};
    cout << Solution().rob(nums);
}