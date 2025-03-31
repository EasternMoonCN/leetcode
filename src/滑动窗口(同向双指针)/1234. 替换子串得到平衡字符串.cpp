#include "../utils/common.h"

class Solution {
public:
    // 待替换子串之外的任意字符的出现次数都不超过m，可以通过替换，使s为平衡字符串
    int balancedString(string s) {
        int n = s.size(), m = n / 4;
        unordered_map<char, int> cnt;

        for (char c : s) {
            cnt[c]++;
        }

        // 已经满足，直接返回
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) {
            return 0;
        }

        int left = 0, right = 0;  
        int res = n + 1;
        while (right < n) {
            cnt[s[right++]]--;

            // [left, right - 1] 之外的字符串不超过m，则可以将[left, right - 1] 替换，使s平衡(超过m的字符必须要被替换)
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                res = min(res, right - left);
                cnt[s[left++]]++;
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().balancedString("QWER");
}