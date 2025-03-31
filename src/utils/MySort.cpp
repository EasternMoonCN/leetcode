//
// Created by EasternMoon on 2024/7/9.
//

#include "MySort.h"

void MySort::selectSort(vector<int> &nums) {
    // nums.size() - 1：最后一个一定时最大值，无需排序，未排序空间[i, n - 1]
    for (int i = 0; i < nums.size() - 1; ++i) {
        int k = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            // 记录最小值小标
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        // 将最小元素与未排序首个空间交换
        swap(nums[i], nums[k]);
    }
}

void MySort::bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }
}

void MySort::insertSort(vector<int> &nums) {
    // 未排序区间[i, n]，选择基准元素num[i]
    for (int i = 1; i < nums.size(); ++i) {
        int base = nums[i], j = i - 1;
        // 找到插入位置j+1，所有元素后移
        while (j >= 0 && base < nums[j]) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = base;
        /*// 已排序空间[j, i]，基准元素num[i] 进行比较
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
            }
        }*/
    }
}

int partition(vector<int> &nums, int left, int right) {
    int base = left;
    while (left < right) {
        while (left < right && nums[base] <= nums[right]) {
            --right;
        }
        while (left < right && nums[base] >= nums[left]) {
            ++left;
        }
        swap(nums[left], nums[right]);
    }
    swap(nums[base], nums[left]);
    return left;
}

void MySort::quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    // base排好序了
    int base = partition(nums, left, right);
    quickSort(nums, left, base - 1);
    quickSort(nums, base + 1, right);
}


int main() {
    vector<int> nums = {1, 2, 5, 4, 3};
//    MySort::selectSort(nums);
//    MySort::bubbleSort(nums);
//    MySort::insertSort(nums);
    MySort::quickSort(nums, 0, nums.size() - 1);
    common::printVector(nums);
}