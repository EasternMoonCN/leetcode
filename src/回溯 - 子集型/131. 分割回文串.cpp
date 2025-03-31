#include "utils/common.cpp"


class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // dp.assign(n, vector<bool>(n, 0));
        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                // 计算结束下标
                int j = i + len - 1;
                if (j >= n) {
                    break;
                }

                if (len == 1) {
                    // 单字符为回文串
                    dp[i][i] = true;
                } else if (s[i] == s[j]) {
                    if (len == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    
                }
            }
        }

        vector<vector<string>> results;
        backTrack(s, 0, {}, results);
        return results;
    }

    /*
        求字符串的所有分割
    */
    void backTrack(string& s, int i, vector<string> result,
                   vector<vector<string>>& results) {
        if (i == s.size()) {
            results.push_back(result);
            return;
        }

        // 对于子串以i开头，可选结束位置j
        for (int j = i; j < s.size(); ++j) {
            if (dp[i][j]) {
                result.push_back(s.substr(i, j - i + 1));
                backTrack(s, j + 1, result, results);
                result.pop_back();
            }
        }
    }


    vector<string> result;
    vector<vector<string>> results;
    vector<vector<string>> partition2(string s) {
        backTrack2(s, 0, 0);
        return results;
    }

    // 选或不选放逗号
    void backTrack2(string& s, int start, int end) {
        if (end == s.size()) {
            if (start == end) {
                results.push_back(result);
            }
            return;
        }

        // 选
        string t = s.substr(start, end - start + 1);
        if (check(t)) {
            result.push_back(t);
            backTrack2(s, end + 1, end + 1);
            result.pop_back();
        }

        // 不选
        backTrack2(s, start, end + 1);
    }

    bool check(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main () {
    string s = "aab";

    // Solution().partition(s);
    vector<vector<string>> results;
    Solution().backTrack(s, 0, {}, results);
    common<string>::printVectors(results);
    return 0;
}