class Solution {
    public:
        // 非递减子序列的最大长度
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            vector<int> mem(n, -1);
            auto dfs = [&](this auto&& dfs, int i) -> int {
                if (mem[i] != -1) {
                    return mem[i];
                }
                int res = 0;
                for (int j = 0; j < i; ++j) {
                    if (nums[j] <= nums[i]) {
                        res = max(res, dfs(j));
                    }
                }
                mem[i] = res + 1;
                return mem[i];
            };
    
            int res = n;
            for (int i = 0; i < n; ++i) {
                res = min(res, n - dfs(i));
            }
            return res;
        }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i]) {

                    res = max(res, dp[j]);
                }
            }
            dp[i] = res + 1;
        }
        return n - *max_element(dp.begin(), dp.end());
    }

        // O(Nlog(N))
        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            vector<int> g;
            for (int i = 0; i < n; ++i) {
                // 在g中找一个 > nums[i]的位置，g[i]表示长度为i + 1的非递减子串中的最小值
                auto it = upper_bound(g.begin(), g.end(), nums[i]);
                if (it == g.end()) {
                    g.push_back(nums[i]);
                } else {
                    *it = nums[i];
                }
            }
            return n - g.size();
        }

        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            // dfs(i, j) :当前i处元素为j时，非递减元素最少删除次数
            vector<vector<int>> memo(n ,vector<int>(4, -1));
            function<int(int, int)> dfs = [&](int i, int j) {
                if (i < 0) {
                    return 0;
                }
    
                if (memo[i][j] != -1) {
                    return memo[i][j];
                }
    
                int res = INT_MAX;
                // 当前i处元素为j
                if (nums[i] == j) {
                    // i-1处元素可以小于等于j
                    for (int k = 1; k <= j; ++k) {
                        res = min(res, dfs(i - 1, k));
                    }
                } else {
                    // 当前i处元素不为j
                    // 删除当前元素，前面元素从小于等于j枚举
                    for (int k = 1; k <= j; ++k) {
                        res = min(res, dfs(i - 1, k) + 1);
                    }
                }
                memo[i][j] = res;
                return memo[i][j];
            };
    
            int r1 = dfs(n - 1, 1);
            int r2 = dfs(n - 1, 2);
            int r3 = dfs(n - 1, 3);
            return min(min(r1, r2), r3);
        }

        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            // dfs(i, j) :当前i处元素为j时，非递减元素最少删除次数
            vector<vector<int>> memo(n ,vector<int>(4, -1));
            function<int(int, int)> dfs = [&](int i, int j) {
                if (i < 0) {
                    return 0;
                }
    
                if (memo[i][j] != -1) {
                    return memo[i][j];
                }
    
                int res = INT_MAX;
                for (int k = 1; k <= j; ++k) {
                    res = min(res , dfs(i - 1, k) + (nums[i] != j));
                }
                memo[i][j] = res;
                return memo[i][j];
            };
    
            int r1 = dfs(n - 1, 1);
            int r2 = dfs(n - 1, 2);
            int r3 = dfs(n - 1, 3);
            return min(min(r1, r2), r3);
        }

        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    int res = INT_MAX;
                    for (int k = 1; k <= j; ++k) {
                        res = min(res, dp[i][k] + (nums[i] != j));
                    }
                    dp[i + 1][j] = res;
                }
            }
            return min(min(dp[n][1], dp[n][2]), dp[n][3]);
        }

        int minimumOperations(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(4, 0);
    
            for (int i = 0; i < n; ++i) {
                // dp[j] 依赖dp[k](k <= j)
                for (int j = 3; j >= 1; --j) {
                    // 从小于j中取最小值
                    dp[j] = *min_element(dp.begin() + 1, dp.begin() + j + 1) + (j != nums[i]);
                }
            }
    
            return min(min(dp[1], dp[2]), dp[3]);
        }
        
    };

