#include "../utils/common.h"

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int left = 0, right = 1;
        int index = 0, res = 1;
        while (right < n) {
            char c = s[right];
            if (c == s[right - 1]) {
                // 第一次重复为0，后续为index
                left = index;
                // 记录本次前一个元素重复的位置
                index = right;
            }
            right++;
            res = max(right - left, res);
        }
        return res;
    }
};