#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
    int singleNumber(vector<int>& nums) {
        // 元素值：元素次数
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = map[nums[i]] + 1;
        }
        for(pair<int, int> entry : map) {
            if(entry.second == 1) {
                return entry.first;
            }
        }
        return -1;
    }
    */
    // 1. 所有元素的第i位相加，如果答案没有贡献，则一定为0，如果答案贡献了，则一定为1
    int singleNumber(vector<int>& nums) {
        int res = 0;
        // 遍历所有位数(包括符号位)
        for(int i = 0; i < 32; ++i) {
            int bit = 0;
            for (int num : nums) {
                // 计算所有元素的第i位和
                bit += (num >> i) & 1;
            }
            // 如果答案元素贡献了
            if(bit % 3) {
                res |= 1 << i;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3, 3, 3, 1, 4, 4};
    cout << Solution().singleNumber(nums);
}