#include "utils/common.cpp"

/**
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 */
class Solution {
public:

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> record(nums.size(), true);
        dfs(nums, res, cur, record);
        return res;
    }

    void dfs(vector<int>& choices, vector<vector<int>>& res, vector<int>& cur, vector<bool> record) {
        if (cur.size() == choices.size()) {
            vector<vector<int>>::iterator it = find(res.begin(), res.end(), cur);
            if (it == res.end()) {
                res.push_back(cur);
            }
            return;
        }
        for (int i = 0; i < choices.size(); ++i) {
            if (record[i]) {
                record[i] = false;
                cur.push_back(choices[i]);
                dfs(choices, res, cur, record);
                record[i] = true;
                cur.pop_back();
            }
        }
    }
};

int main() {
    // vector<int> num = {1, 2, 3};
    // vector<vector<int>> nums = {{1, 2, 3}};
    // cout << (find(nums.begin(), nums.end(), num) != nums.end());
    vector<int> nums = {1 ,1 ,2};
    common<int>::printVectors(Solution().permuteUnique(nums));
    return 0;
}