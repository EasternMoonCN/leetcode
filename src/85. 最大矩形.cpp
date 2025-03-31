#include "utils/common.cpp"

/**
 * 和211最大正方形类似
 */
class Solution
{
public:
    int maximalRectangle2(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int length = 0, width = 0;
        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (matrix[i - 1][j - 1] - '0')
                {
                    dp[i][j].first = dp[i][j - 1].first + 1;
                    dp[i][j].second = dp[i - 1][j].second + 1;
                    if (dp[i][j].first * dp[i][j].second > length * width) {
                        length = dp[i][j].first;
                        width = dp[i][j].second;
                    }
                }
            }
        }

        for_each(dp.begin(), dp.end(), [](vector<pair<int,int>> data){
            for_each(data.begin(), data.end(), [](pair<int,int> p){
                string s = "(" + to_string(p.first) + "," + to_string(p.second) + ") ";
                cout << s;
            });
            cout << endl;
        });

        return length * width;
    }

    int maximalRectangle3(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        // 矩阵第 i 行第 j 列元素的左边连续 1 的数量 (可能达到的最大宽度)
        vector<vector<int>> lefts(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] - '0') {
                    lefts[i][j] = j ? lefts[i][j - 1] + 1 : 1;
                }
            }
        }
        int area = 0;
        // 以ij为左下角1矩形的最大值
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!(matrix[i][j] - '0')) {
                    continue;
                }
                int width = INT_MAX;
                for (int k = i; k >= 0; --k) {
                    width = min(width, lefts[k][j]);
                    area = max(area, width * (i - k + 1));
                }
            }
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        // 矩阵第 i 行第 j 列元素的左边连续 1 的数量 (可能达到的最大宽度)
        vector<vector<int>> lefts(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] - '0') {
                    lefts[i][j] = j ? lefts[i][j - 1] + 1 : 1;
                }
            }
        }

        int area = 0;
        // 单调栈
        for (int j = 0; j < m; ++j) {
            // 第j行中，当宽度为left[i][j]，所能达到的上界和下界
            vector<int> ups(n), downs(n);
            stack<int> is;
            for (int i = 0; i < n; ++i) {
                while (!is.empty() && lefts[is.top()][j] >= lefts[i][j]) {
                    is.pop();
                }
                ups[i] = is.empty() ? -1 : is.top();
                is.push(i);
            }

            is = stack<int>();
            for (int i = n - 1; i >= 0; --i) {
                while (!is.empty() && lefts[is.top()][j] >= lefts[i][j]) {
                    is.pop();
                }
                downs[i] = is.empty() ? n : is.top();
                is.push(i);
            }


            for (int i = 0; i < n; ++i) {
                area = max(area, lefts[i][j] * (downs[i] - ups[i] - 1));
            }
        }
        return area;
    }
};

int main()
{
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << Solution().maximalRectangle(matrix);
}