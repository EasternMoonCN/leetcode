class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            unordered_map<int, vector<int>> umap;
            int n = nums.size();
            // 按数值统计出现位置
            for (int i = 0; i < nums.size(); ++i) {
                umap[nums[i]].push_back(i);
            }
    
            unordered_map<int, int> cmap;
            // 使用引用，改变原数组
            for (auto& [_, p] : umap) {
                int i0 = p[0];
                // 添加哨兵，标识最后一个相同元素位置
                p.insert(p.begin(), p.back()- n);
                // 添加哨兵，标识第一个相同元素位置
                p.push_back(i0 + n);
            }
    
            // vector<int> res;
            for (auto& q : queries) {   // 数组中下标的值，使用引用直接替换
                auto& p = umap[nums[q]];
                if (p.size() == 3) {
                    q = -1;
                } else {
                    // 从数组中找下标q，得到数组下标
                    int j = lower_bound(p.begin(), p.end(), q) - p.begin();
                    q = min(q - p[j - 1], p[j + 1] - q);
                }
            }
            return queries;
    
    
    
        //     int n = nums.size();
        //     vector<int> pre(n, INT_MAX), suf(n, INT_MAX);
        //     for (int i = 0; i < n; ++i) {
    
        //         for (int j = i - 1; j >= 0; --j) {
        //             if (nums[i] == nums[j]) {
        //                 pre[i] = min(pre[i], min(i - j, n - i + j));
        //             }
        //         }
        //     }
    
        //     for (int i = n - 1; i >= 0; --i) {
        //         for (int j = i + 1; j < n; ++j) {
        //             if (nums[i] == nums[j]) {
        //                 suf[i] = min(suf[i], min(j - i, n - j + i));
        //             }
        //         }
        //     }
    
        //     vector<int> res;
        //     for (int query : queries) {
        //         int min_value = min(pre[query], suf[query]);
        //         res.push_back(min_value != INT_MAX ? min_value : -1);
        //     }
        //     return res;
    
        }
    };