#include "utils/head.h"
/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中
设置位
 的个数（也被称为汉明重量）。
*/

class Solution
{
public:
    // n & (n−1)，其运算结果恰为把 n 的二进制位中的最低位的 1 变为 0 之后的结果
    int hammingWeight(int n)
    {
        int res = 0;
        // 每次都讲n到最低位置为0
        while (n)
        {
            n &= n - 1;
            ++res;
        }
        return res;
    }
    /*
    int hammingWeight(int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res += n >> i & 1;
        }
        return res;
    }
    */
};