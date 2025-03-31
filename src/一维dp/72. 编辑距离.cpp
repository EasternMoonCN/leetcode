#include "../utils/common.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int maxValue = max(n, m);
        vector<vector<int>> cache(n, vector<int>(m, maxValue));
        auto dfs = [&](auto&& dfs, int i, int j) {
            if (i < 0) {
                return j + 1;
            }
            if (j < 0) {
                return i + 1;
            }
            if (cache[i][j] != maxValue) {
                return cache[i][j];
            }
            if (word1[i] == word2[j]) {
                cache[i][j] = dfs(dfs, i - 1, j - 1);
            } else {
                // dfs(i, j - 1) ：插入
                // dfs(i - 1, j) ：删除
                // dfs(i - 1, j - 1) : 替换
                cache[i][j] =  min(min(dfs(dfs, i, j - 1), dfs(dfs, i - 1, j)), dfs(dfs, i - 1, j - 1)) + 1;
            }
            return cache[i][j];
        };
        return dfs(dfs, n - 1, m - 1);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int maxValue = max(n, m);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, maxValue));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < m; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            int prev = dp[0];
            dp[0]++;
            for (int j = 0; j < m; ++j) {
                int temp = dp[j + 1];
                if (word1[i] == word2[j]) {
                    dp[j + 1] = prev;
                } else {
                    dp[j + 1] = min(min(dp[j], dp[j + 1]), prev) + 1;
                }
                prev = temp;
            }
        }
        return dp[m];
    }
};