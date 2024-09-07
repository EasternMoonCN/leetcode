#include "utils/head.h"
/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

dp[i]:长度为i的二叉搜索树个数
*/
class Solution
{
public:

    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        // 长度为i
        for (int i = 2; i <= n; i++)
        {
            // 左子树长度
            for (int l = 0; l < i; l++)
            {
                // 左子树个数*右子树个数
                dp[i] += dp[l] * dp[i - l - 1];
            }
            
        }
        return dp[n];
    }

    /*
    int numTrees(int n)
    {
        return dfs(1, n);
    }
    */

    /*
        以start，end为节点，能构造多少中二叉树
    */
    int dfs(int start, int end)
    {
        int num = 0;

        // 只有一个节点，或者没有节点，都只构造一颗二叉树
        if (start >= end)
        {
            return 1;
        }
        // 以i作为根节点
        for (int i = start; i <= end; i++)
        {
            // 左边种类数 * 右边种类数 = 以i为根节点的总种类数 （num表示不同根节点积累的种类数）
            num += dfs(start, i - 1) * dfs(i + 1, end);
        }
        return num;
    }
};

int main()
{
    cout << Solution().numTrees(3);
}