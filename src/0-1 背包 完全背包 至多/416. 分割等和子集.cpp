class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum & 1) {
                return false;
            }
            // 选一些数，让其和为pos
            int pos = sum >> 1;
            int n = nums.size();
            vector<vector<int>> memory(n, vector<int>(pos + 1, -1));
    
            auto dfs = [&](this auto&& dfs, int i, int left) -> bool {
                if (i < 0) {
                    return !left;
                }
    
                if (memory[i][left] != -1) {
                    return memory[i][left];
                }
                int b1 = false;
                if (left >= nums[i]) {
                    b1 = dfs(i - 1, left - nums[i]);
                }
                memory[i][left] = b1 || dfs(i - 1, left);
                return memory[i][left];
            };
            return dfs(n - 1, pos);
        }

        // bool canPartition(vector<int>& nums) {
        //     int sum = accumulate(nums.begin(), nums.end(), 0);
        //     if (sum & 1) {
        //         return false;
        //     }
        //     // 选一些数，让其和为pos
        //     int pos = sum >> 1;
        //     int n = nums.size();
        //     vector<vector<bool>> dp(n + 1, vector<bool>(pos + 1, false));
    
        //     // for (int i = 0; i <=n; ++i) {
        //     //     dp[i][0] = true;
        //     // }
        //     dp[0][0] = true;
    
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j <= pos; ++j) {
        //             if (j >= nums[i]) {
        //                 dp[i + 1][j] = dp[i][j - nums[i]] || dp[i][j];
        //             } else {
        //                 dp[i + 1][j] = dp[i][j];
        //             }
        //         }
        //     }
    
        //     // for_each(dp.begin(), dp.end(), [](vector<bool> b) -> void{
        //     //     for_each(b.begin(), b.end(), [](bool v) -> void {
        //     //         cout << v << " ";
        //     //     });
        //     //     cout << endl;
        //     // });
    
        //     return dp[n][pos];
    
        // }

        // bool canPartition(vector<int>& nums) {
        //     int sum = accumulate(nums.begin(), nums.end(), 0);
        //     if (sum & 1) {
        //         return false;
        //     }
        //     // 选一些数，让其和为pos
        //     int pos = sum >> 1;
        //     int n = nums.size();
        //     vector<bool> dp(pos + 1, false);
    
        //     // for (int i = 0; i <=n; ++i) {
        //     //     dp[i][0] = true;
        //     // }
        //     dp[0] = true;
    
        //     for (int i = 0; i < n; ++i) {
        //         // for (int j = 0; j <= pos; ++j) {
        //         for (int j = pos; j > 0; --j) {
        //             if (j >= nums[i]) {
        //                 dp[j] = dp[j - nums[i]] || dp[j];
        //                 // dp[i + 1][j] = dp[i][j - nums[i]] || dp[i][j];
        //             } else {
        //                 dp[j] = dp[j];
        //                 // dp[i + 1][j] = dp[i][j];
        //             }
        //         }
        //     }
    
        //     // for_each(dp.begin(), dp.end(), [](vector<bool> b) -> void{
        //     //     for_each(b.begin(), b.end(), [](bool v) -> void {
        //     //         cout << v << " ";
        //     //     });
        //     //     cout << endl;
        //     // });
    
        //     return dp[pos];
    
        // }
    };