#include "../utils/common.cpp"

class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int total = 0;
            dfs(i, 0, 0, total);
            res += total;
        }
        return res;
    }

    void dfs(int n, int index, int sum, int& total) {
        string s = to_string(n * n);
        if (index == s.size()) {
            // 构成惩罚数
            if (sum == n) {
                total = n * n;
            }
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            int num = stoi(s.substr(index, i - index + 1));
            dfs(n, i + 1, sum + num, total);
            if (total != 0) {
                return;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int result = Solution().punishmentNumber(37);
    return 0;
}