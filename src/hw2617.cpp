#include "utils/common.cpp"

class Solution
{
public:
    int minimumVisitedCells(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid.at(0).size();
        // dp[i][j]：抵达i，j所经过的最小网格数
        // dp[i][j] = ∑(dp[i][k]) +  ∑（dp[k][j]）
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - max(n, m)));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int k = 0; k < i; k++)
            {
                // j行加上本单元格值，能到达i行
                if (grid[k][0] + k >= i)
                {
                    dp[i][0] = min(dp[i][0], dp[k][0] + 1);
                }
            }
        }
        for (int j = 1; j < m; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (grid[0][k] + k >= j)
                {
                    dp[0][j] = min(dp[0][j], dp[0][k] + 1);
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    if (grid[k][j] + k >= i)
                    {
                        dp[i][j] = min(dp[i][j], dp[k][j] + 1);
                    }
                }

                for (int k = 0; k < j; k++)
                {
                    if (grid[i][k] + k >= j)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][k] + 1);
                    }
                }
            }
        }

        return dp[n - 1][m - 1] >= INT_MAX - max(n, m) ? -1 : dp[n - 1][m - 1];
    }

    int minimumVisitedCells2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // dist[i][j] 表示到大i，j所需的最小单元格
        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[0][0] = 1;
        // 每行(列)维护一个最小堆，堆顶的第一个元素表示到达当前单元格所属最小单元格数量，第二个元素表示是第几列(行)
        // row[i] = (k, j) 表示了从行到达单元格i，j所需最小单元格数量k 
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> row(m), col(n);

        // 如果dist为默认值，或者找到一个更小单元格数量，则更新
        auto update = [](int& x, int y) {
            if (x == -1 || y < x) {
                x = y;
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 移除行堆中不能到达单元格j堆元素
                while (!row[i].empty() && row[i].top().second + grid[i][row[i].top().second] < j) {
                    row[i].pop();
                }
                // 行堆顶元素一定是最小到达单元格j的上一个单元格
                if (!row[i].empty()) {
                    update(dist[i][j], dist[i][row[i].top().second] + 1);
                }

                while (!col[j].empty() && col[j].top().second + grid[col[j].top().second][j] < i) {
                    col[j].pop();
                }
                if (!col[j].empty()) {
                    update(dist[i][j], dist[col[j].top().second][j] + 1);
                }
                // 将当前单元格所需最小单元格数量加入堆
                if (dist[i][j] != -1) {
                    row[i].emplace(dist[i][j], j);
                    col[j].emplace(dist[i][j], i);
                }
            }
        }
        common<int>::printVectors(dist);
        return dist[m - 1][n - 1];
    }

};

int main() {
    vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
    cout << Solution().minimumVisitedCells2(grid);
    return 0;
}