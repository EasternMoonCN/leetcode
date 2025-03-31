#include "../utils/common.h"

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> imap;
        int left = 0, right = 0;
        int n = nums.size();
        int res = 0;
        while (right < n) {
            int num = nums[right++];

            while(imap[num] == k) {
                imap[nums[left++]]--;
            }
            imap[num]++;
            res = max(right - left, res);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,1,2,1,2,1,2};
    int k = 1;
    cout << Solution().maxSubarrayLength(nums, k);
}