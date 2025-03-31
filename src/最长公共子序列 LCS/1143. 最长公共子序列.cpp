class Solution {
    public:
        // o(nm)
        // 已经初始化好了，边界不需要初始化
        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size(), m = text2.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (text1[i] == text2[j]) {
                        dp[i + 1][j + 1] = dp[i][j] + 1;
                    } else {
                        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                    }
                }
            }
            return dp[n][m];
        }

        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size(), m = text2.size();
            vector<int> dp(m + 1, 0);
            for (int i = 0; i < n; ++i) {
                // pre = 0: text2长度为0时，最长子序列长度为0
                for (int j = 0, pre = 0; j < m; ++j) {
                    // 缓存本次被覆盖的dp[j + 1]
                    int tmp = dp[j + 1];
                    if (text1[i] == text2[j]) {
                        // 下次用于用于计算左上角
                        dp[j + 1] = pre + 1;
                    } else {
                        dp[j + 1] = max(dp[j + 1], dp[j]);
                    }
                    pre = tmp;
                }
            }
            return dp[m];
        }

        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size(), m = text2.size();
    
            vector<vector<int>> memory(n, vector<int>(m, -1));
            auto dfs = [&](this auto && dfs, int i, int j) -> int {
                if (i < 0 || j < 0) {
                    return 0;
                }
    
                if (memory[i][j] != -1) {
                    return memory[i][j];
                }
    
                if (text1[i] == text2[j]) {
                    memory[i][j] = dfs(i- 1, j - 1) + 1;
                } else {
                    memory[i][j] = max(dfs(i - 1, j), dfs(i, j - 1));
                }
                return memory[i][j];
            };
    
            return dfs(n - 1, m - 1);
        }
    };