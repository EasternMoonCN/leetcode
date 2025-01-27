#include "utils/head.h"
/*

125. 验证回文串
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        char left, right;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            } else if (!isalnum(s[j])) {
                --j;
                continue;
            }
            if (tolower(s[i]) == tolower(s[j])) {
                ++i;
                --j;
            } else {
                return false;
            }
        }
        return true;
    }
};