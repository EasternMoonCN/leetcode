package solution2537;

import java.util.HashMap;
import java.util.Map;

/**
 * @author moon
 */
class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int n = nums.length, left = 0, pairs = 0;
        long ans = 0;
        for (int right = 0; right < n; ++right) {
            int x = nums[right];

            // 增加次数
            int c = cnt.getOrDefault(x, 0);
            pairs += c;
            cnt.put(x, c + 1);


            while (pairs >= k) {
                x = nums[left++];
                c = cnt.get(x);
                pairs -= c - 1;
                cnt.put(x, c - 1);
            }

            ans += left;
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}
