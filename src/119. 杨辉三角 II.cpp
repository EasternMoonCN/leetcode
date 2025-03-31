#include "utils/common.cpp"

class Solution
{
public:
    // O(N^2)
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> triangle(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i)
        {
            // 第i行有i+1个
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; ++j)
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle[rowIndex];
    }

    vector<int> getRow2(int rowIndex)
    {
        vector<int> numRows(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; ++i)
        {
            // 第i行有i+1个
            for (int j = i - 1; j > 0; --j)
            {
                numRows[j] = numRows[j - 1] + numRows[j];
            }
        }
        return numRows;
    }
};