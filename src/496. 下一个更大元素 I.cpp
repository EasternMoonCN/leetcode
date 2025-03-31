#include "utils/common.cpp"

class Solution {
public:
    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nextMax(n2);
        stack<int> is;
        for (int i = n2 - 1; i >= 0; --i) {
            while (!is.empty() && nums2[i] > nums2[is.top()]) {
                is.pop();
            }
            nextMax[i] = is.empty() ? n2 : is.top();
            is.push(i);
        }

        common<int>::printVector(nextMax);

        vector<int> result(n1);
        for (int i1 = 0; i1 < n1; ++i1) {
            int i2 = 0;
            while (nums1[i1] != nums2[i2]) {
                ++i2;
            }
            result[i1] = nextMax[i2] == n2 ? -1 : nums2[nextMax[i2]];
        }
        return result;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> next;
        stack<int> is;
        for (int i = m - 1; i >= 0; --i) {
            while (!is.empty() && nums2[i] > is.top()) {
                is.pop();
            }
            next[nums2[i]] = is.empty() ? -1 : is.top();
            is.push(nums2[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = next[nums1[i]];
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    common<int>::printVector(Solution().nextGreaterElement(nums1, nums2));
}