class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() > 1) {
            return max(robbing(vector<int>(nums.begin(), nums.end() - 1)), robbing(vector<int>(nums.begin() + 1, nums.end())));
        }
        return nums[0];
    }

    int robbing(vector<int> nums) {
        vector<int> mem(nums.size(), -1);
        auto dfs = [&](this auto && dfs, int i) -> int{
            if (i < 0) {
                return 0;
            }
            if (mem[i] != -1) {
                return mem[i];
            }
            mem[i] = max(nums[i] + dfs(i - 2), dfs(i - 1));
            return mem[i];
        };
        return dfs(nums.size() - 1); 
    }

        int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return nums[0];
        }
        //dp[i][j] ：前i个房屋里，偷不偷第一个 下的最高金额
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        dp[1][0] = nums[1];
        // 偷了第一个，第二个不能偷
        dp[1][1] = nums[0];

        for (int i = 2; i < n; ++i) {
            // 偷i 与 不偷i的最高金额
            dp[i][0] = max(dp[i - 2][0] + nums[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][1] + nums[i], dp[i - 1][1]);
        }

        // 偷了第1个，则第n个不能偷
        return max(dp[n - 1][0], dp[n - 2][1]);
    }
};