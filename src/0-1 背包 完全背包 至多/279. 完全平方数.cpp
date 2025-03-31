class Solution
{
public:
    int numSquares(int n)
    {
        int s = sqrt(n);
        vector<vector<int>> memory(s + 1, vector<int>(n + 1, -1));
        auto dfs = [&](this auto &&dfs, int i, int left) -> int
        {
            if (i < 1)
            {
                return left == 0 ? 0 : n;
            }

            if (memory[i][left] != -1)
            {
                return memory[i][left];
            }
            int n1 = n;
            if (left >= i * i)
            {
                n1 = dfs(i, left - i * i) + 1;
            }
            int n2 = dfs(i - 1, left);
            memory[i][left] = min(n1, n2);
            return memory[i][left];
        };
        return dfs(s, n);
    }

    int numSquares(int n)
    {
        int s = sqrt(n);
        vector<vector<int>> dp(s + 1, vector<int>(n + 1, n + 1));
        for (int i = 0; i <= s; ++i)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= s; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j >= i * i)
                {
                    dp[i][j] = min(dp[i][j - i * i] + 1, dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s][n];
    }

    int numSquares(int n)
    {
        int s = sqrt(n);
        vector<vector<int>> dp(s + 1, vector<int>(n + 1, n + 1));
        dp[0][0] = 0;

        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (j >= (i + 1) * (i + 1))
                {
                    dp[i + 1][j] = min(dp[i + 1][j - (i + 1) * (i + 1)] + 1, dp[i][j]);
                }
                else
                {
                    dp[i + 1][j] = dp[i][j];
                }
            }
        }
        return dp[s][n];
    }

    int numSquares(int n)
    {
        int s = sqrt(n);
        vector<vector<int>> dp(s + 1, vector<int>(n + 1, n + 1));
        dp[0][0] = 0;

        for (int i = 1; i <= s; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (j >= i * i)
                {
                    dp[i][j] = min(dp[i ][j - i * i ] + 1, dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s][n];
    }

    int numSquares(int n)
    {
        int s = sqrt(n);
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (j >= (i + 1) * (i + 1))
                {
                    dp[j] = min(dp[j - (i + 1) * (i + 1)] + 1, dp[j]);
                }
                else
                {
                    dp[j] = dp[j];
                }
            }
        }
        return dp[n];
    }
};