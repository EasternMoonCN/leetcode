#include "../utils/common.cpp"

class Solution {
public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<vector<int>> cache(n, vector<int>(20000, -1));
    //     auto dfs = [&](auto&& dfs, int i, int t) {
    //         if (i < 0) {
    //             return t == target ? 1 : 0;
    //         }
    //         if (cache[i][t + 10000] != -1) {
    //             return cache[i][t + 10000];
    //         }
    //         // 选+
    //         int n1 = dfs(dfs, i - 1, t + nums[i]);
    //         // 选-
    //         int n2 = dfs(dfs, i - 1, t - nums[i]);
    //         cache[i][t + 10000] = n1 + n2;
    //         return cache[i][t + 10000];
    //     };
    //     return dfs(dfs, n - 1, 0);
    // }

    // 
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     target = accumulate(nums.begin(), nums.end(), target);

    //     // 正数部分取不了整
    //     if (target < 0 || target & 1) {
    //         return 0;
    //     }

    //     // 正整数部分和
    //     target >>= 1;

    //     auto dfs = [&](auto&& dfs, int i, int c) {
    //         if (i < 0) {
    //             return c == 0 ? 1 : 0;
    //         }

    //         if (c < nums[i]) {
    //             return dfs(dfs, i - 1, c);
    //         }
    //         return dfs(dfs, i - 1, c) + dfs(dfs, i - 1, c - nums[i]);
    //     };
    //     return dfs(dfs, n - 1, target);
    // }

    /**
     * 当前操作：枚举第i个元素选不选，不选：目标和t不变，选：目标和 t+nums[i]
     * 子问题：从前i个元素选取目标和为t的方案数
     * 下一个子问题：
     *      不选：从前i-1个元素在目标和为t下的最大价值
     *      选：从前i-1个元素在目标和为t+nums[i]下的最大价值
     */
    // dfs(i) ：前i个物品在cap容量下的最大价值，
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);

        // 正数部分取不了整
        if (target + s < 0 || (target + s ) & 1) {
            return 0;
        }

        // 正整数部分和
        int p = (target + s) >> 1;

        
        vector<vector<int>> cache(n, vector<int>(p + 1, -1));
        auto dfs = [&](auto&& dfs, int i, int t) {
            if (i < 0) {
                return t == p ? 1 : 0;
            }
            if (cache[i][t]  != -1) {
                return cache[i][t];
            }
            // 选i+不选i
            if (t + nums[i] <= p) {
                cache[i][t] = dfs(dfs, i - 1, t + nums[i]) + dfs(dfs, i - 1, t);
                return cache[i][t];
            }
            // 只能不选i
            cache[i][t] = dfs(dfs, i - 1, t);
            return cache[i][t];
        };
        return dfs(dfs, n - 1, 0);
    }
    
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << Solution().findTargetSumWays(nums, target);
}