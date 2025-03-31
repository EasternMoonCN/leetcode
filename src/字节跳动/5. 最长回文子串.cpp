#include "../utils/common.cpp"

/**
 * 给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成
 */

class Solution {
public:
    bool isPalidrome(string s, int start, int len) {
        int left = start, right = start + len - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome2(string s) {
        int n = s.size(), start = 0, len = 1;
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                if (isPalidrome(s, i, l)) {
                    start = i;
                    len = l;
                    break;
                }
            }
        }
        return s.substr(start, len);
    }
};