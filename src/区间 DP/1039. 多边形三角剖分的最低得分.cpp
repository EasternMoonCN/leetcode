class Solution {
    public:
        int minScoreTriangulation(vector<int>& values) {
            int n = values.size();
            vector<vector<int>> dp(n, vector<int>(n, 0));
    
            for (int i = n - 3; i >= 0; --i) {
                for (int j = i + 2; j < n; ++j) {
                    int res = INT_MAX;
                    for (int k = i + 1; k < j; ++k) {
                        res = min(res, dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                    }
                    dp[i][j] = res;
                }
            }
            return dp[0][n - 1];
        }
        // // O(N^3):N^2个状态，每个状态N个时间
        // int minScoreTriangulation(vector<int>& values) {
        //     // i到j这个多变形的最低得分
        //     // 从i，j中不断枚举k，ikj构成三角形，i->k->i构成新的多变形（子问题）,j->k->j构成新的多变形（子问题）
        //     function<int(int, int)> dfs = [&](int i, int j) -> int {
        //         if (i + 1 == j) {
        //             return 0;
        //         }
        //         int res = INT_MAX;
        //         for (int k = i + 1; k < j; ++k) {
        //             res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
        //         }
        //         return res;
        //     };
        //     return dfs(0, values.size() - 1);
        // }
        // int minScoreTriangulation(vector<int>& values) {
        //     // i到j这个多变形的最低得分
        //     // 从i，j中不断枚举k，ikj构成三角形，i->k->i构成新的多变形（子问题）,j->k->j构成新的多变形（子问题）
        //     function<int(int, int)> dfs = [&](int i, int j) -> int {
        //         if (i + 1 == j) {
        //             return 0;
        //         }
        //         int res = INT_MAX;
        //         for (int k = i + 1; k < j; ++k) {
        //             res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
        //         }
        //         return res;
        //     };
        //     return dfs(0, values.size() - 1);
        // }
    };