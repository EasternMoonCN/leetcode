class Solution {
    public:
    // O(NM)
    // 依赖左上角，左，上，所以要初始化
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min({dp[i + 1][j], dp[i][j + 1], dp[i][j]}) + 1;
                }
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);

        // for (int i = 0; i <= n; ++i) {
        //     dp[i][0] = i;
        // }
        for (int j = 0; j <= m; ++j) {
            dp[j] = j;
        }

        for (int i = 0; i < n; ++i) {
            int prev = dp[0];
            dp[0] = i + 1;
            for (int j = 0; j < m; ++j) {
                int temp = dp[j + 1];
                if (word1[i] == word2[j]) {
                    dp[j + 1] = prev;
                } else {
                    dp[j + 1] = min({dp[j], dp[j + 1], prev}) + 1;
                }
                prev = temp;
            }
        }



        return dp[m];
    }
        int minDistance(string word1, string word2) {
            int n = word1.size(), m = word2.size();
            vector<vector<int>> memory(n, vector<int>(m, -1));
            auto dfs = [&](this auto&& dfs, int i, int j) -> int {
                if (i < 0 || j < 0) {
                    // 插入另一个所需次数
                    return max(max(i, j) + 1, 0);
                }
    
                if (memory[i][j] != -1) {
                    return memory[i][j];
                }
    
                if (word1[i] == word2[j]) {
                    memory[i][j] = dfs(i - 1, j - 1);
                } else {
                    int ic = dfs(i, j - 1);
                    int dc = dfs(i - 1, j);
                    int uc = dfs(i - 1, j - 1);
                    memory[i][j] =  min(min(ic, dc), uc) + 1;
                }
                return memory[i][j];
            };
    
            return dfs(n - 1, m - 1);
        }
    };