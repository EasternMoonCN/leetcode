class Solution {
    public:
        long long maxScore(vector<int>& nums, int x) {
            int n = nums.size();
            vector<long long> dp(2, 0);
            for (int i = n - 1; i >= 0; --i) {
                // 节点i的奇偶性：0偶，1基
                int j = nums[i] & 1;
                // 奇偶性不相同情况下去选和不选最大值
                dp[!j] = max(dp[j] + nums[i] - x, dp[!j]);
                // 奇偶性相同情况下必须选
                dp[j] = dp[j] + nums[i];
            }
            return dp[nums[0] & 1];
        }
    
        // dfs[i, j]：在下标[i, n - 1]中选一个子序列，其第一个数的奇偶性为j时最大得分。
        // dp[i][j]：在子序列[i, n - 1] 的子序列中，奇偶性为j的最大得分
        // long long maxScore(vector<int>& nums, int x) {
        //     int n = nums.size();
        //     vector<vector<long long>> dp(n + 1, vector<long long>(2,0));
        //     for (int i = n - 1; i >= 0; --i) {
        //         // 节点i的奇偶性：0偶，1基
        //         int j = nums[i] & 1;
        //         // 奇偶性相同情况下必须选
        //         dp[i][j] = dp[i + 1][j] + nums[i];
        //         // 奇偶性不相同情况下去选和不选最大值
        //         dp[i][!j] = max(dp[i + 1][j] + nums[i] - x, dp[i + 1][!j]);
        //     }
        //     return dp[0][nums[0] & 1];
        // }
    
        // long long maxScore(vector<int>& nums, int x) {
        //     int n = nums.size();
        //     vector<vector<long long>> mem(n, vector<long long>(2, -1)); 
        //     // dfs(i, flag)：表示 “从 i 开始，且 i 之前选的元素奇偶性是 flag，最大得分
        //     // dfs(i, flag)：在flag(上一个选择的性质)性质下，[0, i]中选不选i的最大值
        //     function<long long(int, bool)> dfs = [&](int i, bool flag) ->long long {
        //         if (i == n) {
        //             return 0;
        //         }
        //         if(mem[i][flag] != -1) {
        //             return mem[i][flag];
        //         }
        //         // 奇偶性相同时不需选
        //         if ((nums[i] & 1) == flag) {
        //             mem[i][flag] = dfs(i + 1, flag) + nums[i];
        //         } else {
        //             // 奇偶性不同时，去选和不选之间的最大值
        //             mem[i][flag] =  max(dfs(i + 1, !flag) - x + nums[i], dfs(i + 1, flag));// 没选状态不要变
        //         }
        //         return mem[i][flag];
        //     };
        //     return dfs(0, nums[0] & 1);
        // }
    
        // long long maxScore(vector<int>& nums, int x) {
        //     int n = nums.size();
        //     vector<int> mem(n, -1);
        //     //
        //     // dfs[i]：选择第一个元素为i，开始的最大得分，即[i, n]
        //     //         由于记录了当前选择的位置，所以不要记录奇偶性
        //     auto dfs = [&](this auto&& dfs, int i) -> int {
        //         if (mem[i] != -1) {
        //             return mem[i];
        //         }
        //         int res = 0;
        //         for (int j = i + 1; j < n; ++j) {
        //             if ((nums[j] & 1) == (nums[i] & 1)) {
        //                 res = max(res, dfs(j));
        //             } else {
        //                 // 无论奇偶是否变化，都要减去
        //                 res = max(res, dfs(j) - x);
        //             }
        //         }
        //         mem[i] = res + nums[i];
        //         return mem[i];
        //     };
        //     return dfs(0);
        // }
    
        // dfs[i] ：[i + 1, n) 的最大分数，还需要加上nums[i]
        // long long maxScore(vector<int>& nums, int x) {
        //     int n = nums.size();
        //     vector<int> mem(n, -1);
        //     // dfs[i]：从i开始的最大得分,由于记录了当前选择的位置，所以不要记录奇偶性
        //     auto dfs = [&](this auto&& dfs, int i) -> int {
        //         if (mem[i] != -1) {
        //             return mem[i];
        //         }
        //         int res = 0;
        //         for (int j = i + 1; j < n; ++j) {
        //             if ((nums[j] & 1) == (nums[i] & 1)) {
        //                 res = max(res, dfs(j) + nums[j]);
        //             } else {
        //                 // 无论奇偶是否变化，都要减去
        //                 res = max(res, dfs(j) + nums[j] - x);
        //             }
        //         }
        //         mem[i] = res;
        //         return mem[i];
        //     };
        //     return nums[0] + dfs(0);
        // }
    };