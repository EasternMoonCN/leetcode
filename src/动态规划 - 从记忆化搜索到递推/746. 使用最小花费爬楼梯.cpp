#include "../utils/common.cpp"

class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> mem(n, - 1);
    //     auto dfs = [&](this auto && dfs, int i) {
    //         if (i <= 1) {
    //             return cost[i];
    //         }
    //         if(mem[i] != -1) {
    //             return mem[i];
    //         }
    //         mem[i] = cost[i] + min(dfs(i - 1), dfs(i - 2));
    //         return mem[i];
    //     };
    //     return min(dfs(n - 1), dfs(n - 2));
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for (int i = 2; i < n; ++i) {
        //     dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        // }
        // return min(dp[n - 1], dp[n - 2]);

        int f0 = 0, f1 = 0, f2;
        for (int i = 0; i < n; ++i) {
            f2 = cost[i] + min(f0, f1);
            f0 = f1;
            f1 = f2;
        }
        return min(f0, f1);
    }
};