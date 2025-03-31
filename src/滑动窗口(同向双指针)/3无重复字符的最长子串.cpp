#include "../utils/common.cpp"


/**
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 
子串的长度。
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
        int n = s.size();
        int left = 0, right = 0;
        int longest = 0;

        unordered_set<char> cset;
        

        while (right < n) {
            char c = s[right++];
            // 尝试扩大右边界，去除扩大右边界中所有不满足的情况，求取满足情况下最大值
            while (cset.count(c))
            {
                cset.erase(s[left++]);
            }
            cset.insert(c);
            longest = max(longest, right - left);
        }
        return longest;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring("pwwkew");
}