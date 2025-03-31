#include "../utils/common.cpp"

class Solution {
public:
    int totalNQueens(int n) {
        // vector<string> result;
        // vector<vector<string>> results;
        vector<bool> rows(n, false);
        vector<bool> fDiags(2 * n, false);
        vector<bool> sDiags(2 * n, false);
        int result = 0;


        auto dfs = [&](auto && dfs, int i) {
            if (i == n) {
                result++;
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
                dfs(dfs, i + 1);
                rows[j] = false;
                fDiags[n + i - j] = false;
                sDiags[i + j] = false;
            }
        };

        dfs(dfs, 0);
        return result;
    }
};