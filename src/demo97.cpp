#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空
子字符串
：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。


状态：ij子串s，t长度
当前状态dp[i][j] 由 dp[i - 1][j] 或 dp[i][j - 1] 过来
当s3[i][j] == s1[i - j]，dp[i][j] = dp[i - 1][j]
当s3[i][j] == s2[j - i], dp[i][j] = dp[i][j- 1]
否则 s3[i][j]= false
*/
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // s3长度必须为s1和s2之和
        if (s3.size() != n + m)
        {
            return false;
        }

        dp[0][0] = true;
        /*
        // 当j为0时
        for (int i = 1; i <= n; i++)
        {
            if (s1[i] == s3[i])
            {
                dp[i][0] = dp[i - 1][0];
            }
        }
        // 当i为0时
        for (int j = 1; j <= m; j++)
        {
            if (s2[j] == s3[j])
            {
                dp[0][j] = dp[0][j - 1];
            }
        }*/

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                /*
                第i+j 个字符从 s1中取，当s3[i + j - 1] == s1[i - 1]，dp[i][j] = dp[i - 1][j];
                第i+j 个字符从 s2中取，当s3[i + j - 1] == s2[j - i], dp[i][j] = dp[i][j- 1];
                两个中，只要有一个为ture就行 */
                if (i > 0 && s3[i + j - 1] == s1[i - 1])
                {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
                if (j > 0 && s3[i + j - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i][j]  | dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{
    cout << Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}