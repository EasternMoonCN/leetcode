class Solution {
    public:
        // // 最长公共子序列
        // int longestPalindromeSubseq(string s) {
        //     int n = s.size();
        //     string rs;
        //     rs.reserve(n);
        //     reverse_copy(s.begin(), s.end(), rs.begin());
    
        //     function<int(int ,int)> dfs = [&](int i, int j) -> int {
        //         if (i < 0 || j < 0) {
        //             return 0;
        //         }
        //         if (s[i] == rs[j]) {
        //             return dfs(i - 1, j -1) + 1;
        //         } else {
        //             return max(dfs(i - 1, j), dfs(i, j - 1));
        //         }
    
        //     };
        //     return dfs(n - 1, n -1);
        // }
    
        // int longestPalindromeSubseq(string s) {
        //     // function<bool(string)> isPalidrome(string s) {
        //     //     int left = 0, right = s.size() - 1;
        //     //     while (left <= right) {
        //     //         if (s[left++] != s[right--]) {
        //     //             return false;
        //     //         }
        //     //     }
        //     //     return true;
        //     // }
    
        //     function<int(int, int)> dfs = [&](int i, int j) -> int {
        //         if (i > j) {
        //             return 0;
        //         }
        //         if (i == j) {
        //             return 1;
        //         }
        //         if (s[i] == s[j]) {
        //             return dfs(i + 1, j - 1) + 2;
        //         } else {
        //             return max(dfs(i, j - 1), dfs(i + 1, j));
        //         }
        //     };
        //     return dfs(0, s.size() - 1);
        // }
    
        int longestPalindromeSubseq(string s) {
            int n = s.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));
            for (int i = n - 1; i >= 0; --i) {
                dp[i][i] = 1;
                for (int j = i + 1; j < n; ++j) { 
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }  else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[0][n - 1];
        }
    };