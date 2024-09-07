//
// Created by EasternMoon on 2024/6/25.
//
#include "utils/head.h"
/*
 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */
class Solution {
public:
    unordered_map<char, vector<char> > num2char = {
            {'2' , {'a', 'b', 'c'}},
            {'3' , {'d', 'e', 'f'}},
            {'4' , {'g', 'h', 'i'}},
            {'5' , {'j', 'k', 'l'}},
            {'6' , {'m', 'n', 'o'}},
            {'7' , {'p', 'q', 'r', 's'}},
            {'8' , {'t', 'u', 'v'}},
            {'9' , {'w', 'x', 'y', 'z'}},
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res;
        backtrack(digits, 0, "", res);
        return res;
    }

    void backtrack(string digits, int index, string s, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        vector<char> nums = num2char[c];
        for (int i = 0; i < nums.size(); ++i) {
            backtrack(digits, index + 1, s + nums[i], res);
        }
    }
};

void printVal(string val) {
    cout << val << endl;
}

int main() {
    vector<string> res = Solution().letterCombinations("23");
    for_each(res.begin(), res.end(), printVal);
}