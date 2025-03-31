class Solution {
    public:
        int maxOperations(vector<int>& nums) {
            int n = nums.size();
            // 串[i, j] 最大操作数目
            function<int(int ,int, int)> dfs = [&](int start, int end, int target) -> int {
                vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
                for (int i = end - 1; i >= start; --i) {
                    for (int j = i + 1; j <= end; ++j) {
                        if (nums[i] + nums[i + 1] == target)
                            dp[i][j + 1] = max(dp[i][j + 1], dp[i + 2][j + 1] + 1);
                        if (nums[j - 1] + nums[j] == target)
                            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j - 1] + 1);
                        if (nums[i] + nums[j] == target)
                            dp[i][j + 1] = max(dp[i][j + 1], dp[i + 1][j] + 1);
                    }
                }
                return dp[start][end + 1];
            };
    
    
            // vector<vector<int>> memo(n, vector<int>(n, -1)); // -1 表示没有计算过
            // function<int(int, int, int)> dfs = [&](int i, int j,
            //                                        int target) -> int {
            //     if (i >= j)
            //         return 0;
            //     int& res = memo[i][j]; // 注意这里是引用
            //     if (res != -1)
            //         return res; // 之前计算过
            //     res = 0;
            //     if (nums[i] + nums[i + 1] == target)
            //         res = max(res, dfs(i + 2, j, target) + 1);
            //     if (nums[j - 1] + nums[j] == target)
            //         res = max(res, dfs(i, j - 2, target) + 1);
            //     if (nums[i] + nums[j] == target)
            //         res = max(res, dfs(i + 1, j - 1, target) + 1);
            //     return res;
            // };
    
            int res1 = dfs(2, n - 1, nums[0] + nums[1]);
            int res2 = dfs(0, n - 3, nums[n - 2] + nums[n - 1]);
            int res3 = dfs(1, n - 2, nums[0] + nums[n - 1]);
            return max(max(res1, res2), res3) + 1;
        }
    };