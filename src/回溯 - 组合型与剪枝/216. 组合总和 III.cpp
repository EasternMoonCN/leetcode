#include "utils/common.cpp"

class Solution {
public:
    vector<vector<int>> results;
    vector<int> result;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return results;
    }

    void dfs2(int k, int n, int start) {
        if (result.size() == k) {
            if (n == 0) {
                results.push_back(result);
            }
            return;
        }

        // if (n < 0 || start > 9) {
        //     return;
        // }

        for (int i = start; i <= 9; ++i) {

            if (n - i < 0 || result.size() + 1 > k) {
                break;
            }

            result.push_back(i);
            dfs2(k, n - i, i + 1);
            result.pop_back();
        }
    }

    void dfs(int k, int n, int start) {
        if (result.size() == k) {
            if (n == 0) {
                results.push_back(result);
            }
            return;
        }

        if(n - start < 0 || start > 9) {
            return;
        }

        // 不选
        dfs(k, n, start + 1);

        // 选
        if (result.size() + 1 > k) {
            return;
        }
        result.push_back(start);
        dfs(k, n - start, start + 1);
        result.pop_back();

        
    }
};