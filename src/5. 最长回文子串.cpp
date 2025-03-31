#include "utils/common.cpp"

class Solution
{
public:
    string longestPalindrome2(string s)
    {
        int n = s.size(), maxLen = 1, begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        for (int l = 2; l <= n; ++l)
        {
            for (int i = 0; i < n - 1; ++i)
            {
                int j = i + l - 1;
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (l == 2)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && l > maxLen)
                {
                    maxLen = l;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        int longestLen = 0;
        int longestStart = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // dp[i][j] 依赖dp[i + 1][j - 1]
        for (int len = 0; len < n; ++len)
        {
            for (int i = 0; i + len < n; ++i)
            {
                if (len == 0)
                {
                    // 单字符为回文串
                    dp[i][i] = true;
                    longestStart = i;
                    longestLen = 1;
                }
                else if (s[i] == s[i + len])
                {
                    if (len < 2)
                    {
                        dp[i][i + len] = true;
                    }
                    else
                    {
                        dp[i][i + len] = dp[i + 1][i + len - 1];
                    }

                    if (dp[i][i + len] && longestLen < len + 1)
                    {
                        longestLen = max(longestLen, len + 1);
                        longestStart = i;
                    }
                }
            }
        }

        return s.substr(longestStart, longestLen);
    }
};

int main() {
    string s = "babad";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}