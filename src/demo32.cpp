#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。*/

/*
状态：
i,
状态转移：
dp[i] 表示以下标 i 字符结尾的最长有效括号的长度

1. 以 ( 结尾的子串对应的 dp 值必定为 0
s[i]=) 且 s[i-1] = ( ，则 dp[i]=dp[i−2]+2
2. 以 ) 结尾的子串对于的 dp 值 为 如果 i-1 也为左括号，若果有一个（与当前括号对应，则dp为内部长度（dp[i-1]）+外部长度（dp[i-dp[i-1] - 2]） + 2
s[i]=) 且s[i-1] = )  如果s[i-dp[i-1] - 1] = '('，则 dp[i] = dp[i-1] + dp[i-dp[i-1] - 2] + 2
边界：
*/
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n);

        for (int i = 1; i < n; i++)
        {
            // 以（结尾的子串必为0
            if (s[i] == '(')
            {
                continue;
            }
            // 连续两个右括号
            if (s[i - 1] == ')')
            {
                // 查找是否前面有（与i对应
                if (i - dp[i - 1] < 1 || s[i - dp[i - 1] - 1] != '(')
                {
                    continue;
                }
                // 当前最长子串长度为内长度+外长度+2
                dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] >= 2 ? i - dp[i - 1] -2 : 0];
            }
            else {
                // 匹配到连续（），在原子串长度上+2
                dp[i] = 2 + dp[i > 2 ? i - 2 : 0];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    cout << Solution().longestValidParentheses("())");
    return 0;
}