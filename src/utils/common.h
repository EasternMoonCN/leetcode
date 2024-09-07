//
// Created by EasternMoon on 2024/6/27.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <stack>
#include <unordered_set>
#include <list>
#include <cmath>
using namespace std;

template<typename T>
class common {
public:
    static void printVector(vector<T> result);
    static void printVectors(vector<vector<T> > results);
    static void printData(T result);
};

#endif //LEETCODE_COMMON_H
