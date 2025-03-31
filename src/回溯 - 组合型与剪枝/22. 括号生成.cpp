#include "utils/common.cpp"

class Solution {
public:
    string result;
    vector<string> results;
    vector<string> generateParenthesis(int n) {
        backTrack(2 * n, 0);
        return results;
    }

    void backTrack(int n, int left) {
        if (n == 0) {
            results.push_back(result);
            return;
        }

        // 选左
        // 剩余选择个数足以匹配当前再选一个左括号
        if (left + 1 <= n) {
            result.push_back('(');
            backTrack(n - 1, left + 1);
            result.pop_back();
        }
        

        // 选右
        // 必须要现有左括号
        if (left > 0) {
             result.push_back(')');
            backTrack(n - 1, left - 1);
            result.pop_back();
        }
    }

};