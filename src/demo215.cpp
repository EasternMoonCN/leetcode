#include "utils/common.cpp"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return 0;
    }

    void maxHeapify(vector<int>& nums, int i) {
        while (true) {
            int l = left(i), r = right(i), m = i;
            if (l < nums.size() && nums[l] > nums[m]) {
                m = l;
            }
            if (r < nums.size() && nums[r] > nums[m]) {
                m = r;
            }
            if (m == i) {
                break;
            }
            swap(nums[i], nums[m]);
            i = m;
        }
    }

    void maxHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = parent(n - 1); i >= 0; i--)
        {
            maxHeapify(nums, i);
        }
        

    }
    // 索引i的父节点索引
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right (int i) {
        return 2 * i + 2;
    }
};

int main() {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution().maxHeap(nums);
    common<int>::printVector(nums);
}