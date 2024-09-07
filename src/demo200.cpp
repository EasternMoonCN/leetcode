#include "utils/common.cpp"

/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/

class Solution
{
public:

    // int numIslands(vector<vector<char>> &grid)
    // {
    //     int res = 0, rows = grid.size(), cols = grid[0].size();

    //     for (int row = 0; row < rows; ++row)
    //     {
    //         for (int col = 0; col < cols; ++col)
    //         {
    //             if (grid[row][col] == '1')
    //             {
    //                 ++res;
    //                 dfs(grid, row, col, rows, cols);
    //             }
                
                
    //         }
    //     }
    //     return res;
    // }

    // void dfs(vector<vector<char>> &grid, int row, int col, const int& rows, const int& cols) 
    // {
    //     grid[row][col] = '0';
    //     if(row - 1 > 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col, rows, cols);
    //     if(row + 1 < rows && grid[row + 1][col] == '1') dfs(grid, row + 1, col, rows, cols);
    //     if(col - 1 > 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1, rows, cols);
    //     if(col + 1 < cols && grid[row][col + 1] == '1') dfs(grid, row, col + 1, rows, cols);
    // }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};
    cout << Solution().numIslands(grid);
    return 0;
}