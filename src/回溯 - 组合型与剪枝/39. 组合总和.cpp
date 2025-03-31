#include "../utils/common.cpp"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        // sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, {}, results);
        return results;
    }

    void dfs(vector<int>& candidates, int target, int index, vector<int> result,
             vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(result);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                continue;
                // break;
            }
            result.push_back(candidates[i]);
            // 可以重复选择，index为i
            dfs(candidates, target - candidates[i], i, result, results);
            result.pop_back();
        }
    }

        void dfs2(vector<int>& candidates, int target, int index, vector<int> result,
             vector<vector<int>>& results) {
        if (index == candidates.size()) {
            return;
        }
        if (target == 0) {
            results.push_back(result);
            return;
        }

        if (target - candidates[index] >= 0) {
            // 选
            result.push_back(candidates[index]);
            dfs2(candidates, target - candidates[index], index, result, results);
            result.pop_back();
        }
        // 不选
        dfs(candidates, target, index + 1, result, results);
    }
};