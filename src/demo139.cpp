#include "utils/common.cpp"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        // 空串可以被表示
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            // 遍历s[0, i)中每个分割节点，其中dp[j] 记录了s[0, j - 1]能否被表示，只需判断s[j, i - j]是否在字典中包含
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
                
            }
        }
        return dp[n];
    }
};


int main() {
    vector<string> wordDict = {"leet", "code"};
    cout << Solution().wordBreak("leetcode", wordDict);
    return 0;
}