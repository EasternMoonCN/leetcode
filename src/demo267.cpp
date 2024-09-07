#include <iostream>
#include <vector>
using namespace std;

/*
0. 0 ^ a = a
1. a ^ a ^ b ^ c = b ^ c
2. x & -x => x中最低位l为1的位置
3. (b ^ c) ^ -(b ^ c) => b和c一定在第l位有一个为1，一个为0 
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 先求出两个一次元素异或值
        int xor_sum = 0;
        for (int num : nums) {
            xor_sum ^= num;
        }
        // 最低位l一定为1，其余为0
        int bit_l = xor_sum & -xor_sum;
        // 所有元素分为两类：第l位为0，第l位为1，只有一个元素的必分到两个类中，两个元素的分到同一个类中
        int bit_l0 = 0, bit_l1 = 0;
        for (int num : nums) {
            // 只有第l位为1，其余为0
            if(num & bit_l) {
                // 第l位非0互相异或，最终直有一个第l位为1的一个元素
                bit_l0 ^= num;
            } else {
                // 第l位0互相异或，最终只有一个第l位为0的一个元素
                bit_l1 ^= num;
            }
        }
        return {bit_l0, bit_l1};
    }
};