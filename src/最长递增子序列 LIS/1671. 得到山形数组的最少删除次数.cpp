class Solution {
    public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> memo1, memo2;

        // dfs1(i) ：以i为结束，需要删除几个才能达到递增
        auto dfs1 = [&](this auto&& dfs1, int i) -> int {
            if (memo1.count(i)) {
                return memo1[i];
            }
            // 如果当前nums[i]为最小值，则前面的都要删除，要删除i次
            int res = i;
            // 遍历当前尾巴为i，前一个选择的j
            for (int j = 0; j < i; ++j) {
                // 选择的j需要构成递增
                if (nums[j] < nums[i]) {
                    // j到i之间需要删除的字符数量
                    res = min(res, dfs1(j) + (i - j - 1));
                }
            }
            memo1[i] = res;
            return res;
        };

        // dfs2(i) ：当前i为开始，需要删除几个才能达到递减
        auto dfs2 = [&](this auto&& dfs2, int i) -> int {
            if (memo2.count(i)) {
                return memo2[i];
            }
            int res = n - i - 1;
            // 遍历当前开始为n，后一个选择的j
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    res = min(res, dfs2(j) + (j - i - 1));
                }
            }
            memo2[i] = res;
            return res;
        };

        int cnt = n;
        for (int i = 1; i < n - 1; ++i) {
            // [0, i] 构成递增，需要删除的字符数
            int left = dfs1(i);
            // [i, n] 构成递减，需要删除的字符数
            int right = dfs2(i);
            // [0, i] 长度
            int prev = i + 1;
            // [i, n] 长度
            int suff = n - i;
            // 字符删除后，需要保证前后都还有字符
            if (prev - left > 1 && suff - right > 1) {
                cnt = min(cnt, left + right);
            }
        }
        return cnt;
    }
};