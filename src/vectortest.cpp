#include "utils/common.cpp"

void normal() {
    vector<int> nums;
    nums.push_back(1);
    nums.back();
    nums.pop_back();
}

int main() {
    vector<int> nums1 {1, 2, 3};
    vector<int> nums2 = vector<int>{nums1.begin(), nums1.end() - 1};
    common<int>::printVector(nums2);
}