class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n + 1, -1);
        auto dfs = [&](this auto && dfs, int i) -> int {
            // 说明是一条正确的方法
            if (i == 0) {
                return 1;
            }
            // 不构成方法
            if (i < 0) {
                return 0;
            }

            if (mem[i] != -1) {
                return mem[i];
            }
            mem[i] = dfs(i - 1) + dfs(i - 2);
            return mem[i];
        };
        return dfs(n);
    }

    int climbStairs(int n) {
        // if (n == 1) {
        //     return 1;
        // }
        // vector<int> dp(n + 1, 0);
        // dp[1] = 1;
        // dp[2] = 2;
        // for (int i = 3; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];

        int f0 = 0, f1 = 1, f2;
        for (int i = 0; i< n; ++i) {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};