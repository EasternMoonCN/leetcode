#include "../utils/common.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        auto dfs = [&](this auto && dfs, int i) -> int{
            if (i < 0) {
                return 0;
            }
            if (mem[i] != -1) {
                return mem[i];
            }
            mem[i] = max(nums[i] + dfs(i - 2), dfs(i - 1));
            return mem[i];
        };
        return dfs(nums.size() - 1); 
    }

    int rob(vector<int>& nums) {
        // if (nums.size() == 1) {
        //     return nums[0];
        // }
        // vector<int> dp(nums.size());
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        // for (int i = 2; i < nums.size(); ++i) {
        //     dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        // }
        // return dp[nums.size() - 1];

        int f0 = 0, f1 = 0, f2;
        for (int i = 0; i < nums.size(); ++i) {
            f2 = max(nums[i] + f0, f1);
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
    
};

int main () {
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().rob(nums);
}