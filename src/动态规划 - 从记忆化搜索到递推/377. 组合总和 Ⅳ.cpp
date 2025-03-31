class Solution {
public:
    // int combinationSum4(vector<int>& nums, int target) {
    //     vector<int> memory(target + 1, -1);
    //     auto dfs = [&](this auto&& dfs, int left) -> int {
    //         if (left == 0) {
    //             return 1;
    //         }
    //         if (memory[left] != -1) {
    //             return memory[left];
    //         }
    //         int total = 0;
    //         for (int i = 0; i < nums.size(); ++i) {
    //             if (left < nums[i]) {
    //                 continue;
    //             }
    //             total += dfs(left - nums[i]);
    //         }
    //         memory[left] = total;
    //         return memory[left];
    //     };
    //     return dfs(target);
    // }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};