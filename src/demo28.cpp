#include "utils/head.h"

/*
28. 找出字符串中第一个匹配项的下标
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。
*/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        return kmp(haystack, needle);
    }

    // kmp算法：避免haystack主串中回溯，先求出needle子串中next数组（最长前后缀长度），不匹配时，可以从next[j-1]开始比较
    int kmp(string haystack, string needle)
    {
        // 获取next数组：next[i] 表示长度为i的串中，最长前后缀长度
        vector<int> next = getNext(needle);
        int i = 0, j = 0, hn = haystack.size(), nn = needle.size();
        while (i < hn)
        {
            // 匹配时，主串子串后移
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                // 子串已经到达了0，没有前缀匹配，主串直接后移
                if (j == 0)
                {
                    ++i;
                }
                // 子串还没有到达0，存在前缀匹配，匹配的前缀为next[j - 1]
                else
                {
                    j = next[j - 1];
                }
            }

            // 达到子串最大长度，返回起始点
            if (j == nn)
            {
                return i - j;
            }
        }

        return -1;
    }

    vector<int> getNext(string needle)
    {
        int n = needle.size(), i = 1, j = 0;
        vector<int> next(n, 0);
        while (i < n)
        {
            // 后前缀匹配，next[i]为匹配的字符个数，同时寻找下一个
            if (needle[i] == needle[j])
            {
                next[i] = j + 1;
                ++i;
                ++j;
            }
            else
            {
                // 前缀到达了0，后缀与前缀没有公共部分，直接后移
                if (j == 0)
                {
                    next[i] = 0;
                    ++i;
                }
                // 前缀未到达0，后缀与前缀存在公共部分，前缀移动到更短的公共部分
                else
                {
                    j = next[j - 1];
                }
            }
        }
        return next;
    }

    /*
       int strStr(string haystack, string needle) {
           if(haystack.size() < needle.size()) {
               return -1;
           }
           bool flag;
           for(int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
               flag = true;
               for(int j = 0; j < needle.size(); ++j) {
                   if(haystack[i+j] != needle[j]) {
                       flag = false;
                       break;
                   }
               }
               if(flag) {
                   return i;
               }
           }
           return -1;
       }
       */
};

void print(int val)
{
    cout << val << " ";
}

int main()
{
    // vector<int> next = Solution().getNext("ABACABAB");
    // for_each(next.begin(), next.end(), print);
    int i = Solution().strStr("leetcode", "leeto");
    cout << i << endl;
}