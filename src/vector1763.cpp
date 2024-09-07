#include "utils/head.h"

/*

1763. 最长的美好子字符串

当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。
比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。

*/
class Solution
{
public:
    // 找到s[start, end] 中所有非法字符（即只出现了大写或小写的字符），非法字符将美好字符划分了不同的等份，最佳美好字符一定在这些等份中
    void dfs(const string &s, int start, int end, int &maxPos, int &maxLen)
    {
        if (start >= end)
        {
            return;
        }
        int lower = 0, upper = 0;
        for (int i = start; i <= end; ++i)
        {
            if (islower(s[i]))
            {
                lower |= 1 << (s[i] - 'a');
            }
            else
            {
                upper |= 1 << (s[i] - 'A');
            }
        }
        if (lower == upper)
        {
            if (end - start + 1 > maxLen)
            {
                maxPos = start;
                maxLen = end - start + 1;
            }
            return;
        }
        // 有效字符
        int valid = lower & upper;
        int pos = start;
        while (pos <= end)
        {
            // 开始遍历下一段，更新起点
            start = pos;    
            while (pos <= end && valid & (1 << (tolower(s[pos]) - 'a')))
            {
                // // s[pos] 为非法字符，即s[start, end]只出现了大写或小写
                ++pos;
            }
            dfs(s, start, pos - 1, maxPos, maxLen);
            ++pos;
        }
    }

    string longestNiceSubstring(string s)
    {
        int maxPos = 0, maxLen = 0;
        dfs(s, 0, s.size() - 1, maxPos, maxLen);
        return s.substr(maxPos, maxLen);
    }

    /*
        string dfs(string s, int left, int right)
        {
            if (right < left)
            {
                return "";
            }
            int lower = 0, upper = 0;
            for (int i = left; i <= right; i++)
            {
                if (islower(s[i]))
                {
                    lower |= 1 << (s[i] - 'a');
                }
                else
                {
                    upper |= 1 << (s[i] - 'A');
                }
            }
            // 满足
            if (lower == upper)
            {
                return s.substr(left, right - left + 1);
            }
            // s[left, right] 不满足，找到不满足的字符
            int lu = lower ^ upper;
            // 找到第一个不满足的字符
            int i = left;
            for (; i <= right; i++)
            {
                // 找到不满足的字符，即出现在lu中字符
                if (lu & 1 << (tolower([i]) - 'a')) {
                        break;
                    }
            }
            // s[i] 为非法字符串，即s[i] 一定不为最美字符，直接遍历其左边，或其右边
            string left_res = dfs(s, left, i - 1);
            string right_res = dfs(s, i + 1, right);
            return left_res.size() >= right_res.size() ? left_res : right_res;

        }

        string longestNiceSubstring(string s)
        {
            return dfs(s, 0, s.size() - 1);
        }

    */
    /*
        // 枚举
        string longestNiceSubstring(string s) {
            // lower : 小写字母位图表示，每位表示字符是否出现
            // upper : 大写字母位图
            // max_len， : 最大长度；start_index：开始坐标
            int lower, upper, max_len = 0, start_index = 0;
            for (int i = 0; i < s.size() - 1; ++i) {
                lower = upper = 0;
                // 计算位图
                for (int j = i; j < s.size(); ++j) {
                    if (islower(s[j])) {
                    // if (s[j] >= 'a') {
                        lower |= 1 << (s[j] - 'a');
                    } else {
                        upper |= 1 << (s[j] - 'A');
                    }
                    // s[i, j] 是否满足要求
                    if (!(lower ^ upper) && j - i + 1 > max_len) {
                        start_index = i;
                        max_len = j - i + 1;
                    }
                }
            }
            return s.substr(start_index, max_len);
        }
        */
};

int main()
{
    cout << Solution().longestNiceSubstring("dDzeE");
}