#include "utils/head.h"

/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
*/

class Solution
{
public:
    static void printVal(int val)
    {
        cout << val << " ";
    }
    static void printVector(vector<int> nums)
    {
        for_each(nums.begin(), nums.end(), printVal);
        cout << endl;
    }

    /*
dp[i][j]:字符串 t 中从位置 i 开始往后字符 j 第一次出现的位置。

*/
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(26, m));
        for (int i = m - 1; i >= 0; --i)
        {
            // 遍历26个字母
            for (int j = 0; j < 26; ++j)
            {
                // t[i] = j => dp[i][j] = i (本位置出现字符j)
                if (t[i] == 'a' + j)
                {
                    dp[i][j] = i;
                }
                // dp[i][j] = dp[i+1][j](出现字符j的位置与i+1一致)
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        for_each(dp.begin(), dp.end(), printVector);
        cout << endl;

        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            // 第j行出现字符s[i]的位置
            j = dp[j][s[i] - 'a'];
            if (j < m)
            {
                // 从j+1中查找下一个字符
                ++j;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    /*
        bool isSubsequence(string s, string t) {
            int i = 0, j = 0, sn = s.size(), tn = t.size();
            while(i < sn && j < tn) {
                if(s[i] == t[j]) {
                    ++i; ++j;
                } else {
                    ++j;
                }
            }
            return i == sn;
        }*/
};

int main()
{
    // string s = "ab", t = "baab";
    string s = "abc", t = "ahbgdc";
    cout << Solution().isSubsequence(s, t);
}