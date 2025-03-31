#include "utils/common.cpp"

/**
 * 75. 颜色分类
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]
 */
class Solution {
public:
    // 第一次排序1，第二次排序2
    void sortColors3(vector<int>& nums) {
        int p = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p++]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p++]);
            }
        }
    }

    // p0，p1分别指向要交换到位置
    void sortColors4(vector<int>& nums) {
        int p0 = 0, p1 = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (p0 == p1) {
                    swap(nums[i], nums[p0++]);
                    // 当前p0位置放好
                    p1++;
                } else {
                    //p0后面有排序好的p1
                    swap(nums[i], nums[p0++]);
                    swap(nums[i], nums[p1++]);
                }
                
            } else if (nums[i] == 1) {
                swap(nums[i], nums[p1++]);
            }
        }
    }

    // 0从头开始，2从后开始
    void sortColors4(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1, i = 0;
        while (i <= p2) {
            if (nums[i] == 1) {
                swap(nums[i++], nums[p0++]);
            } else if (nums[i] == 2) {
                // 交换完后，i可能是2或0
                swap(nums[i], nums[p2--]);
            } else {
                i++;
            }
        }
    }

    void sortColors2(vector<int>& nums) {
        // 分别指向1，2开头
        int oneBegin = -1, twoBegin = -1;
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (oneBegin != - 1) {
                    swap(nums[i], nums[oneBegin++]);
                    if (twoBegin != -1) {
                        swap(nums[i], nums[twoBegin++]);
                    }
                } else if (twoBegin != -1) {
                    swap(nums[i], nums[twoBegin++]);
                }
            } else if (nums[i] == 1) {
                if (twoBegin != -1) {
                    if (oneBegin == -1) {
                        oneBegin = twoBegin;
                    }
                    swap(nums[i], nums[twoBegin++]);
                } else if (oneBegin == -1) {
                    oneBegin = i;
                }
            } else {
                if (twoBegin == -1) {
                    twoBegin = i;
                }
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 1};
    Solution().sortColors(nums);
    common<int>::printVector(nums);
}