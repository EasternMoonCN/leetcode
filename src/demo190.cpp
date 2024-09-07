#include "utils/head.h"

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        // 01010101010101010101010101010101
        // uint32_t m1 = 0x55555555;
        uint32_t m1 = 0b01010101010101010101010101010101;
        // 00110011001100110011001100110011
        uint32_t m2 = 0x33333333;
        // 00001111000011110000111100001111
        uint32_t m4 = 0x0f0f0f0f;
        // 00000000111111110000000011111111
        uint32_t m8 = 0x00ff00ff;
        // 相邻1位
        n = ((n & m1) << 1) | (n >> 1 & m1);
        // 相邻2位
        n = ((n & m2) << 2) | (n >> 2 & m2);
        // 相邻4位
        n = ((n & m4) << 4) | (n >> 4 & m4);
        // 相邻8位
        n = ((n & m8) << 8) | (n >> 8 & m8);
        // 相邻16位
        return (n << 16) | (n >> 16);
    }

    /*
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i)
        {
            // n >> i & 1 ： 每次取n中第i位
            // (n >> i & 1) << (31 - i) ：将第i位移到第31-i位
            res |= (n >> i & 1) << (31 - i);
        }
        return res;
    }*/
};

int main()
{
    uint32_t n = 964176192;
    cout << Solution().reverseBits(n);
}