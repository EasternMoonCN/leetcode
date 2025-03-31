#include "utils/common.cpp"

class Solution
{
public:
    bool dfs(string& s, unordered_set<string> &sets, int i, int j)
    {
        if (!sets.count(s.substr(i, j))) {
            return false;
        }
        if (i + j == s.size()) {
            return true;
        }
        for (int k = 1; k <= s.size() - i - j; ++k) {
            if (dfs(s, sets, i + j, k)) {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> sets;
        for (string word : wordDict) {
            sets.insert(word);
        }

        int n = s.size();
        for (int i = 1; i <= n; ++i)
        {
            if (dfs(s, sets, 0, i) ) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<string> wordDict = {"leet", "code"};
    cout << Solution().wordBreak("leetcode", wordDict);
    return 0;
}