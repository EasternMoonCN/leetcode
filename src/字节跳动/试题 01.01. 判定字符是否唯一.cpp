#include "../utils/common.cpp"

/**
 * 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：
输入: s = "leetcode"
输出: false 

示例 2：

输入: s = "abc"
输出: true
限制：

0 <= len(s) <= 100 
s[i]仅包含小写字母
如果你不使用额外的数据结构，会很加分。
 */

class Solution {
public:
    // bool isUnique(string astr) {
    //     unordered_set<char> cset;
    //     for (char c : astr) {
    //         if (cset.count(c)) {
    //             return false;
    //         }
    //         cset.insert(c);
    //     }
    //     return true;
    // }

    // bool isUnique(string astr) {
    //     int bit = 0;
    //     for (char c : astr) {
    //         if ((bit >> (c - 'a')) & 1) {
    //             return false;
    //         }
    //         bit = bit ^ (1 << (c - 'a'));
    //     }
    //     return true;
    // }

     bool isUnique(string astr) {
        int bit = 0;
        for (char c : astr) {
            int mark = 1 << (c - 'a');
            if (bit & mark) {
                return false;
            }
            bit = bit | mark;
        }
        return true;
    }
};