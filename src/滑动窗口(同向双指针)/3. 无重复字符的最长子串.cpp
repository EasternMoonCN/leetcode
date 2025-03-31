#include "../utils/common.cpp"
class Solution {
public:
    // 时间复杂度：o(N)，空间复杂度：O(128 或 1 或 s中不重复元素个数)
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> cset;
        int n = s.size(), l = 0, res = 0;
        for (int r = 0; r < n; ++r) {
            while (cset.count(s[r])) {
                cset.erase(s[l++]);
            }
            cset.insert(s[r]);
            res = max(r - l + 1, res);
        }
        return res;
    }
};