#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


/**
 * nlog(100)：遍历n个值，每次堆化log(100)
 */
class Solution
{
public:
    vector<int> top100(vector<int> nums)
    {

        // 最小堆
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            if (pq.size() < 100) {
                pq.push(num);
            } else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }

        }
 
        vector<int> res;

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;

    }
};

int main()
{
    vector<int> nums(2000000, 0);
    // cout << RAND_MAX << endl;
    for (int i = 0; i < nums.size(); ++i) {
        // 返回一个 0 到 RAND_MAX（2147483647）之间的伪随机整数
        nums[i] = rand() % 2000000;
        // cout << nums[i] << " ";
    }
    cout << endl;
    nums = Solution().top100(nums);
    for_each(nums.begin(), nums.end(), [](int num) -> void {
        cout << num << " ";
    });
    return 0;
}