#include "utils/head.h"

int minimumOperations(vector<int> &nums)
{

    int n = nums.size();

    vector<vector<int>> memo(n, vector<int>(4, -1));

    // dfs(i, j)：在索引i处，以j（1，2，3）结尾非递减子序列最小删除次数
    auto dfs = [&](auto &&dfs, int i, int j) -> int
    {
        if (i < 0)
        {

            return 0;
        }

        auto &res = memo[i][j];

        if (res != -1)
        {

            return res;
        }

        // 当前i处元素等于j
        if (j == nums[i])
        {

            int mink = INT_MAX / 2;
            
            for (int k = 1; k <= j; k++)
            {
                // i-1处小于j（k）
                mink = min(mink, dfs(dfs, i - 1, k));
            }

            return res = mink;
        }

        int mink = INT_MAX / 2;

        // 当前i处元素不等于j
        for (int k = 1; k <= j; k++)
        {
            // 删除i处元素，保证i-1处元素小于等于j
            mink = min(mink, dfs(dfs, i - 1, k) + 1);
        }

        return res = mink;
    };

    int ans1 = dfs(dfs, n - 1, 1);

    int ans2 = dfs(dfs, n - 1, 2);

    int ans3 = dfs(dfs, n - 1, 3);

    return min(min(ans1, ans2), ans3);
}
int main()
{

    int n = 5;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }

    unordered_set<int> cset;
    cset.insert(1);
    cset.erase(1);
}