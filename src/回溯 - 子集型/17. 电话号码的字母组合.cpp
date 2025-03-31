#include "utils/common.cpp"

class Solution {
public:
    vector<string> numToStr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> results;
    string result;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        backTrack(digits, 0);
        return results;
    }

    void backTrack(const string& digits, int start) {
        if (result.size() == digits.size()) {
            results.push_back(result);
            return;
        }

        char c = digits[start];
        for (char c : numToStr[c - '0']) {
            result.push_back(c);
            backTrack(digits, start + 1);
            result.pop_back();
        }
    }
};