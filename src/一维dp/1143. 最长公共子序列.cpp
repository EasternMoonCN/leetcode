#include "../utils/common.h"

class Solution {
public:
    // 选i，选j
    // 选i，不选j
    // 不选i，选j
    // 不选i，不选j
    // dfs(i, j) = max(dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1,j - 1) + 1) s[i] == t[j] => dfs(i, j) = dfs(i -1, j - 1) + 1
    // dfs(i, j) = max(dfs(i - 1, j), dfs(i, j - 1), dfs(i - 1,j - 1))     s[i] != t[j] => dfs(i, j) = max(dfs(i - 1, j), dfs(i, j - 1))
    // 时间复杂读O(nm)：记录化搜索，s和t中每个元素只遍历一次，非基于化搜索，2^n * 2^m * nm
    // 空间复杂度O(nm)
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.size(), m = text2.size();
    //     vector<vector<int>> cache(n, vector(m, -1));
    //     auto dfs = [&](auto&& dfs, int i, int j) {
    //         if (i < 0 || j < 0) {
    //             return 0;
    //         }
    //         if (cache[i][j] != -1) {
    //             return cache[i][j];
    //         }

    //         if (text1[i] == text2[j]) {
    //             cache[i][j] = dfs(dfs, i - 1, j - 1) + 1;
    //         } else {
    //             cache[i][j] = max(dfs(dfs, i - 1, j), dfs(dfs, i, j - 1));
    //         }

    //         return cache[i][j];
    //     };

        
    //     return dfs(dfs, n - 1, m - 1);
    // }

        // int longestCommonSubsequence(string s, string t) {
    //     int n = s.size(), m = t.size();
    //     vector<vector<int>> dp(n + 1, vector(m + 1, 0));
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < m; ++j) {
    //             if (s[i] == t[j]) {
    //                 dp[i + 1][j + 1] = dp[i][j] + 1;
    //             } else {
    //                 dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; ++i) {
            // 用于存储左上方状态(左上的状态会被刚刚覆盖掉)
            int prev = 0;
            for (int j = 0; j < m; ++j) {
                int tmp = dp[j + 1];
                if (s[i] == t[j]) {
                    dp[j + 1] = prev + 1;
                } else {
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                prev = tmp;
            }
        }
        return dp[m];
    }
};