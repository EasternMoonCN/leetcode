class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1000000007;
        vector<int> memory(high + 1, -1);
        auto dfs = [&](this auto && dfs, int i) -> int {
            if (i < 0) {
                return 0;
            }
            if (i == 0) {
                return 1;
            }
            if (memory[i] != -1) {
                return memory[i];
            }
            memory[i] = (dfs(i - zero) + dfs(i - one)) % MOD;
            return memory[i];
        };

        int ans = 0;
        for (int i = low; i <= high; ++i) {
            ans = (ans + dfs(i)) % MOD;
        }
        return ans;
    }

    // int countGoodStrings(int low, int high, int zero, int one) {
    //     vector<int> memory(high + 1, -1);
    //     const int MOD = 1000000007;
    //     auto dfs = [&](this auto && dfs, int len) -> long long {
    //         if (len > high) {
    //             return 0;
    //         }
    //         if (memory[len] != -1) {
    //             return memory[len];
    //         }
    //         long long total = 0;
    //         if (len >= low) {
    //             total = (total + 1) % MOD;
    //         }
    //         if (len + zero <= high) {
    //             total = (total + dfs(len + zero)) % MOD;
    //         }
    //         if (len + one <= high) {
    //             total = (total + dfs(len + one)) % MOD;
    //         }
    //         memory[len] = total;
    //         return total;
    //     };
    //     return dfs(0);
    // }

    // int countGoodStrings(int low, int high, int zero, int one) {
    //     const int MOD = 1000000007;
    //     // 构造长为i字符串的方案数
    //     vector<int> dp(high + 1, 0);
    //     // 空串方案数为1
    //     dp[0] = 1;
    //     int ans = 0;
    //     for (int j = 0; j <= high; ++j) {
    //         if (j >= zero) {
    //             dp[j] = (dp[j] + dp[j - zero]) % MOD;
    //         }
    //         if (j >= one) {
    //             dp[j] = (dp[j] + dp[j - one]) % MOD;
    //         }
    //         // [low, hight] 所有方案数
    //         if (j >= low) {
    //             ans = (ans + dp[j]) % MOD;
    //         }
    //     }
    //     return ans;
    // }
};