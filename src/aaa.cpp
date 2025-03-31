/**
 * 小美玩大富翁游戏，游戏中有n+1个城市排成一排，编号0-n，第 i 个城市上有一个数字a_i，表示到达第i个城市可以获得个a_i金币。每轮开始小美会获得4张卡牌，分别可以跳跃1，2，3，4个城市，当小美用完这4张卡牌时，会开启新的一轮。

初始时，小美拥有0枚金币，在任意时刻，小美的金币数量都不能小于0，请计算，小美从第0个城市出发，到达第n个城市，最多可以获得多少枚金币。

作者：lllllllllan
链接：https://www.nowcoder.com/feed/main/detail/48471dc1426d41aba665e0ebf555c660?sourceSSR=search
来源：牛客网
 */
#include "utils/common.cpp"
class Solution
{
public:
    int solve(vector<int> nums)
    {
        int n = nums.size();
        auto dfs = [&](auto &&dfs, int i, set<int> iset) -> int
        {
            if (i <= 0)
            {
                return i == 0 ? nums[0] : INT_MIN;
            }

            if (iset.size() == 4)
            {
                iset.clear();
            }

            int r = 0;
            for (int j = 1; j <= 4; ++j)
            {
                if (iset.count(j))
                {
                    continue;
                }
                iset.insert(j);
                r = max(r, dfs(dfs, i - j, iset));
                iset.erase(j);
            }
            r += nums[i];
            return r;
        };
        return dfs(dfs, n - 1, {});
    }


};

int main()
{
    Solution sl1;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Test Case 1: " << sl1.solve(nums1) << " (Expected: 25)" << endl;
    return 0;
}