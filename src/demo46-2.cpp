#include "utils/common.cpp"

class Solution {
public:


    vector<vector<int> > permute2(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            temp.push_back(nums[i]);
            // 只从头遍历了，没有打乱剩下的遍历
            for (int j = 0; j < n; j++)
            {
                if (i != j) {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;

    }

    vector<vector<int> > permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        set<int> choice;
        dfs(nums, res, cur, choice);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, set<int>& choice) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (choice.count(i)) {
                continue;
            }
            cur.push_back(nums[i]);
            choice.insert(i);
            dfs(nums, res, cur, choice);
            choice.erase(i);
            cur.pop_back();
        }
        
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    common<int>::printVectors(Solution().permute(nums));
}