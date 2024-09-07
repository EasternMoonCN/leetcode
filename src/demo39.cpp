//
// Created by EasternMoon on 2024/6/26.
//
#include "utils/head.h"

/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 */

class Solution {
public:
    void backtrack(vector<int> candidates, int target, int index, vector<int> result, vector<vector<int> >& results) {
        if (!target) {
            results.push_back(result);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                continue;
            }
            result.push_back(candidates[i]);
            // index = i : 可以重复
            backtrack(candidates, target - candidates[i], i, result, results);
            result.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > results;
        backtrack(candidates, target, 0, vector<int>(), results);
        return results;
    }
};
void printData(int data) {
    cout << data << " ";
}

void printResult(vector<int> result) {
    for_each(result.begin(), result.end(), printData);
    cout << endl;
}

int main () {
    vector<int> candidates = {2, 3, 7};
    int target = 7;
    vector<vector<int> > results = Solution().combinationSum(candidates, target);
    for_each(results.begin(), results.end(), printResult);
}