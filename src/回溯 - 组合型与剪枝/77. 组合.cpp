#include "utils/common.cpp"

class Solution {
public:
    vector<vector<int>> results;
    vector<int> result;
    vector<vector<int>> combine2(int n, int k) {
        backTrack2(n, k, 1);
        return results;
    }

    void backTrack2(int n, int k, int start) {
        if (result.size() == k) {
            results.push_back(result);
            return;
        }

        // 剩余可选择个数不足以填充k个，进行剪枝
        if (n - start + 1 < k - result.size()) {
            return;
        }

        for (int i = start; i <= n; ++i) {
            result.push_back(i);
            backTrack2(n, k, i + 1);
            result.pop_back();
        }
    } 


    vector<vector<int>> combine(int n, int k) {
        backTrack(n, k, 1);
        return results;
    }

    void backTrack(int n, int k, int start) {
        if (result.size() == k) {
            results.push_back(result);
            return;
        }

        // 剩余可选择个数不足以填充k个，进行剪枝
        if (n - start + 1 < k - result.size()) {
            return;
        }


        // 选
        result.push_back(start);
        backTrack(n, k, start + 1);
        result.pop_back();


        // 不选
        backTrack(n, k, start + 1);
    } 
};