#include "utils/common.cpp"

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        backTrack(nums, {}, results, 0);
        return results;
    }

    // 每次考虑的是元素i放与不放，直到遍历完整个数组
    void backTrack(vector<int>& nums, vector<int> result, vector<vector<int>>& results, int start) {
        if (start == nums.size()) {
            results.push_back(result);
            return;
        }

        // 只有两个选择
        result.push_back(nums[start]);
        // 放元素nums[start]
        backTrack(nums, result, results, start + 1);
        result.pop_back();
        // 不放元素nums[start]
        backTrack(nums, result, results, start + 1);
    }

    // n个数字的子集对应（0-2^n）的进制表示，其中每一位表示是否选（1选，0不选）
    vector<vector<int>> subsets3(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<vector<int>> results;
        for (int i = 0; i < n; ++i) {
            // 二进制i表示一种选择
            vector<int> result;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    result.push_back(nums[j]);
                }
            }
            results.push_back(result);
        }
        return results;
    }


    vector<vector<int>> subsets2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> results;
        for (int len = 1; len <= n; ++len) {
            vector<vector<int>> temp;
            backTrack2(nums, {}, temp, 0, len);
            results.insert(results.end(), temp.begin(), temp.end());
        }
    }

    // 每次考虑的是否添加元素i，达到指定长度
    void backTrack2(vector<int>& nums, vector<int> result, vector<vector<int>>& results, int start, int len) {
        if (result.size() == len) {
            results.push_back(result);
            return;
        }

        // 有n中选择
        for (int i = start; i < nums.size(); ++i) {
            if (result.size() > len) {
                break;
            }
            result.push_back(nums[i]);
            backTrack2(nums, result, results, i + 1, len);
            result.pop_back();
        }
    }
};