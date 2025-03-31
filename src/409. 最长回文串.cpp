#include "utils/common.cpp"
class Solution {
public:
    vector<vector<bool>> dp;
    int longestPalindrome(string s) {
        int n = s.size();
        int longest = 0;
        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                if (len == 0) {
                    // 单字符为回文串
                    dp[i][i] = true;
                    longest = 1;
                } else if (s[i] == s[i + len]) {
                    if (len < 2) {
                        dp[i][i + len] = true;
                    } else {
                        dp[i][i + len] = dp[i + 1][i + len - 1];
                    }

                    if (dp[i][i + len]) {
                        longest = max(longest, len + 1);
                    }
                }
            }
        }

        return longest;
    }
};

int main () {
    string s = "aab";

    cout << Solution().longestPalindrome(s) << endl;

    return 0;
}