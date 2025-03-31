#include "../utils/common.cpp"

/**
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 
子串
 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, result = 0, n = s.size();
        set<char> cset;
        while (right < n)
        {
            char c = s[right++];
            while (cset.count(c))
            {
                cset.erase(s[left++]);
            }
            cset.insert(c);
            result = max(result, right - left);
        }
        return result;
    }
};