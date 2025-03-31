#include "../utils/common.cpp"

class Solution {
public:
    vector<vector<int>> results;
    vector<int> result;

    // 字集型，选或不选
    // o(2^n + n)
    vector<vector<int>> subsets2(vector<int>& nums) {
        backTrack2(nums, 0);
        return results;
    }

    void backTrack2(vector<int>& nums, int start) {
        if (start == nums.size()) {
            results.push_back(result);
            return;
        }
        // 选
        result.push_back(nums[start]);
        backTrack2(nums, start + 1);
        result.pop_back();
        // 不选
        backTrack2(nums, start + 1);
    }


    // 站在答案的角度，枚举每一次应该选什么
    vector<vector<int>> subsets(vector<int>& nums) {
        backTrack(nums, 0);
        return results;
    }

    void backTrack(vector<int>& nums, int start) {
        // 每种长度子串都是答案
        results.push_back(result);
        if (start == nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            result.push_back(nums[i]);
            backTrack(nums, i + 1);
            result.pop_back();
        }
    }
};

