#include "utils/common.cpp"

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            unordered_set<char> uset;
            int start = 0, len = 0;
            int i = 0;
            while (i < n) {
                char c = s[i++];
                if (uset.count(c)) {
                    uset.erase(c);
                    start++;
                }
                len = min(len, uset.size());
            }
            return s.substr(start, len);
        }
    };