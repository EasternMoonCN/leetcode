#include "utils/head.h"

/*
76. 最小覆盖子串

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/
class Solution {
public:
    unordered_map<char, int> org, cnt;
    // 判断org中元素及其个数，至少都在cnt中
    bool check() {
        for (pair<const char, int> org_it : org) {
            if (cnt[org_it.first] < org_it.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        // 记录t中元素个数
        for (char c : t) {
            org[c]++;
        }

        int i = 0, j = 0, minLen = INT_MAX, minIndex = 0, n = s.size();
        while (j < n) {
            // 记录元素s[i, j]出现次数，只保留在t中出现过的
            if (org.find(s[j]) != org.end()) {
                cnt[s[j]]++;
            }
            while (check()) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    minIndex = i;
                }
                if (org.find(s[i]) != org.end()) {
                    cnt[s[i]]--;
                }

                ++i;
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(minIndex, minLen);
    }

    /*string minWindow(string s, string t) {
        int minLen = INT_MAX, minIndex = 0, i = 0, j = 0, n = s.size(),
                m = t.size();
        for (int i = 0; i < n; ++i) {
            string temp = t;
            for (int j = i; j < n; ++j) {
                auto it = temp.find(s[j]);
                if (it != temp.npos) {
                    temp.erase(it, 1);
                }
                if (temp.empty()) {
                    if (minLen > j - i + 1) {
                        minIndex = i;
                        minLen = j - i + 1;
                    }

                    break;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minIndex, minLen);
    }*/
};


int main()
{
    // cout << Solution().minWindow("ADOBECODEBANC", "ABC");
    cout << Solution().minWindow("ABC", "B");
}