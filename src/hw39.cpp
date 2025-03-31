#include "utils/common.cpp"

/**
 * 
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 */
class Solution
{
public:

    // 组合数量
    int combinationSum2(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        vector<int> dp(target + 1, 0);
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - candidates[j] >= 0) {
                    dp[i] = max(dp[i], dp[i - candidates[j]]);
                } else {

                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        backTrack(candidates, target, 0, {}, results);
        return results;
    }

    void backTrack(vector<int> &candidates, int target, int begin, vector<int> result, vector<vector<int>> &results)
    {

        if (target == 0)
        {
            results.push_back(result);
            return;
        }

        for (int i = begin; i < candidates.size(); ++i)
        {
            if (target < 0)
            {
                break;
            }
            result.push_back(candidates[i]);
            backTrack(candidates, target - candidates[i], i, result, results);
            result.pop_back();
        }
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    common<int>::printVectors(Solution().combinationSum(candidates, target));
}
