#include "utils/common.cpp"

class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> results;
        
        int n = nums.size();
        vector<bool> visited(n, false);

        auto dfs = [&](auto && dfs, vector<int>& nums) {
            if (result.size() == n) {
                results.push_back(result);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (visited[i]) {
                    continue;
                }
                visited[i] = true;
                result.push_back(nums[i]);
                dfs(dfs, nums);
                result.pop_back();
                visited[i] = false;
            }
        };

        dfs(dfs, nums);
        return results;
    }
};