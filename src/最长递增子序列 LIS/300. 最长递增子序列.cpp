class Solution {
    public:
        // 贪心算法
        // O(Nlog(N))
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            // g[i] ：子序列长度为i+1时的末尾最小值
            vector<int> g;
            for(int i = 0; i < n; ++i) {
                // 在g中寻找插入位置 >= nums[i]
                auto it = lower_bound(g.begin(), g.end(), nums[i]);
                if (it == g.end()) {
                    g.push_back(nums[i]);
                } else {
                    // 相等时候替换无影响
                    // 不相等时候，it所指向的旧值>nums[i]
                    *it = nums[i];
                }
            }
            return g.size();
    
        }

    // O(N^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] ：以i结尾最长递增子序列长度
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            // 找到一个j，拥有最大的dp[j]
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            // 加上以i结尾
            dp[i] += 1;
        }
        return *max_element(dp.begin(), dp.end());

    }
    // O(N^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memory(n, -1);
        // dfs[i]:以num[i]结尾，前i个的最大递子序列长度
        auto dfs = [&](this auto && dfs, int end) -> int {
            if (end == 0) {
                return 1;
            }

            if (memory[end] != -1) {
                return memory[end];
            }

            int res = 0;
            for (int i = 0; i < end; ++i) {
                if (nums[i] < nums[end]) {
                    // 此处是否+1，看res的初始化值
                    // 如果没有满足的nums[i] < nums[end]，则dfs[end]是第一个，应该返回长度1
                    res = max(res, dfs(i));
                }
            }
            // 为什么返回时才+1？
            memory[end] = res + 1;
            return memory[end];
        };
        int ans = 0;
        // 没法确认最后一次选哪个，所以枚举最后一个位置
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

        
        // int lengthOfLIS(vector<int>& nums) {
        //     int n = nums.size();
        //     // nums中有负数存在问题
        //     auto dfs = [&](this auto && dfs, int i, int t) -> int {
        //         if (i < 0) {
        //             return 0;
        //         }
    
        //         if (nums[i] < t) {
        //             return max(dfs(i - 1, nums[i]) + 1, dfs(i - 1, t));
        //         }
        //         return dfs(i - 1, t);
        //     };
        //     return dfs(n - 1, INT_MAX);
        // }
    };