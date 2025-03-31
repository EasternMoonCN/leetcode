#include "../utils/common.cpp"


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n * m == 0) {
            return n + m;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        } 

        for (int j = 1; j <= m; ++j) {
           dp[0][j] = j;
        } 

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 行对应 word1插入值
                    // 列对于 word2插入值 
                    // 行列   word1[i - 1],word2[j - 1]
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        }

        return dp[n][m];
    }
};