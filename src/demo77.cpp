//
// Created by EasternMoon on 2024/6/25.
//
#include "utils/head.h"

/*
 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
 */
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > results;
        backtrack(1, n, k, vector<int>(), results);
        return results;
    }

    void backtrack(int cur, int n, int k, vector<int> result, vector<vector<int> >& results) {
        if (result.size() == k) {
            results.push_back(result);
            return;
        }
        for (int i = cur; i <= n; ++i) {
            result.push_back(i);
            backtrack(i + 1, n, k, result, results);
            result.pop_back();
        }
    }
};
void printData(int data) {
    cout << data << " ";
}

void printResult(vector<int> result) {
    for_each(result.begin(), result.end(), printData);
    cout << endl;
}
int main() {
    vector<vector<int> > results = Solution().combine(4, 2);
    for_each(results.begin(), results.end(), printResult);
}