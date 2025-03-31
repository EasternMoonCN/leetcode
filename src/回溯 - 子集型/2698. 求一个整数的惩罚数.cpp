#include "../utils/common.cpp"

class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            // 求i*i所有分割是否构成惩罚数
            if (dfs(i, 0, 0)) {
                res += i * i;
            }
        }
        return res;
    }

    bool dfs(int n, int index, int sum) {
        // if (sum > n * n) {
        //     return false;
        // }
        string s = to_string(n * n);
        if (index == s.size()) {
            // 构成惩罚数
            if (sum == n) {
                return true;
            } else {
                return false;
            }
        }

        for (int i = index; i < s.size(); ++i) {
            int num = stoi(s.substr(index, i - index + 1));
            if(dfs(n, i + 1, sum + num)) {
                return true;
            }
        }
        return false;
    }
};