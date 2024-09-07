//
// Created by EasternMoon on 2024/7/9.
//

#ifndef LEETCODE_SORT_H
#define LEETCODE_SORT_H
#include "common.cpp"

class MySort {
public:
    /**
     * 「选择排序 selection sort」的工作原理非常直接：开启一个循环，每轮从未排序区间选择最小的元素，将其放到已排序区间的末尾。
     * @param nums
     */
    static void selectSort(vector<int> &nums);
    /**
     * 「冒泡排序 bubble sort」通过连续地比较与交换相邻元素实现排序。这个过程就像气泡从底部升到顶部一样，因此得名冒泡排序
     * @param nums
     */
    static void bubbleSort(vector<int> &nums);
    /**
     * 「插入排序 insertion sort」是一种简单的排序算法，它的工作原理与手动整理一副牌的过程非常相似。
     * 具体来说，我们在未排序区间选择一个基准元素，将该元素与其左侧已排序区间的元素逐一比较大小，并将该元素插入到正确的位置。
     * @param nums
     */
    static void insertSort(vector<int> &nums);
    /**
     * 「快速排序 quick sort」是一种基于分治策略的排序算法，运行高效，应用广泛。
     * 快速排序的核心操作是“哨兵划分”，其目标是：选择数组中的某个元素作为“基准数”，将所有小于基准数的元素移到其左侧，而大于基准数的元素移到其右侧。具
     * @param nums
     */
    static void quickSort(vector<int> &nums, int left, int right);
};


#endif //LEETCODE_SORT_H
