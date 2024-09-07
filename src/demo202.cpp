//
// Created by EasternMoon on 2024/6/24.
//
/*
 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 */
/*
2
2*2=4
4*4=16
1*1+6*6=37
3*3+7*7=58
5*5+8*8=93
9*9+3*3=90
9*9+0*0=81
8*8+1*1=65
6*6+5*5=61
6*6+1*1=37
*/
#include "utils/head.h"
class Solution {
public:
    int getNext(int n) {
        int totalSum = 0;
        while(n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> map;
        while(n != 1) {
            if(map[n]) {
                return false;
            }
            ++map[n];
            n = getNext(n);
        }
        return true;
    }
};
