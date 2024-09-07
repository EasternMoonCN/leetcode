#include "utils/head.h"

/*
134. 加油站
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
*/


class Solution {
public:
    // 从第x个位置出发，无法到达y，则[x，y]中任意位置无法到y。
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), i = 0, step, res = 0;
        while(i < n) {
            step = 0;
            res = 0;
            while (step < n) {
                res += gas[(i + step) % n] - cost[(i + step) % n];
                step++;
                if (res < 0) {
                    break;
                }
            }
            if (res < 0) {
                i = i + step;
            } else {
                return i;
            }
        }
        return -1;
    }
    /*
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int n = gas.size(), res;
            // 遍历每一个加油站
            for (int i = 0; i < n; ++i) {
                res = 0;
                // 从第i个加油站开始前进
                for (int j = 0; j < n; ++j) {
                    res += gas[(i + j) % n];
                    res -= cost[(i + j) % n];
                    //
       到达某一个加油站时，汽油不足，则直接跳出，遍历下一个加油站 if (res < 0) {
                        break;
                    }
                }
                // 从i遍历完后汽油不小于，则直接返回开始的加油站
                if (res >= 0) {
                    return i;
                }
            }
            // 所有起点都遍历完成，直接返回-1
            return -1;
        }
        */
};