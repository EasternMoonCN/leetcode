#include "../utils/common.cpp"
class Solution {
public:
    // 求from全排列到to到最小曼哈顿距离
    int minimumMoves(vector<vector<int>>& grid) {
        // 记录多于1个石头，没有石头坐标
        vector<pair<int, int>> from, to;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        // 多于1个石头坐标
                        from.push_back({i, j});
                    }
                } else {
                    to.push_back({i, j});
                }
            }
        }

        int res = INT_MAX;
        do {
            int total = 0;
            for (int i = 0; i < from.size(); ++i) {
                // 计算曼哈顿距离，即需要移动次数
                total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            res = min(res, total);
        } while (next_permutation(from.begin(), from.end())); // 是否存在下一个字典排列
        return res;
    }
};