#include "utils/common.cpp"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> result;
        vector<vector<string>> results;
        vector<bool> rows(n, false);
        vector<bool> fDiags(2 * n, false);
        vector<bool> sDiags(2 * n, false);


        auto dfs = [&](auto && dfs, int i) {
            if (i == n) {
                results.push_back(result);
                return;
            }

            for (int j = 0; j < n; ++j) {
                // 能不能再第j列加？
                if (rows[j] || fDiags[n + i - j] || sDiags[i + j]) {
                    continue;
                }
                string s(n, '.');
                s[j] = 'Q';
                rows[j] = true;
                fDiags[n + i - j] = true;
                sDiags[i + j] = true;
                result.push_back(s);
                dfs(dfs, i + 1);
                result.pop_back();
                rows[j] = false;
                fDiags[n + i - j] = false;
                sDiags[i + j] = false;
            }
        };

        dfs(dfs, 0);
        return results;
    }
};