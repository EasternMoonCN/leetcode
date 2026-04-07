from typing import List

class Solution:
    # 9, 8, 8 +5(13)-1-2-1-1-2
    def trap(self, height: List[int]) -> int:
        n = len(height)
        i, j = 0, n - 1
        cur_height, ans = 0, 0
        while i <= j:
            if cur_height - min(height[i], height[j]) < 0:
                ans += (max(height[i], height[j]) - cur_height) * (j - i - 1)
                print(ans)
            if height[i] < height[j]:
                if i != 0:
                    ans -= (height[i] - cur_height)
                    print(ans)
                cur_height = max(cur_height, height[i])
                i += 1
            else:
                if j != n - 1:
                    ans -= (cur_height - height[j])
                    print(ans)
                cur_height = max(cur_height, height[j])
                j -= 1
        return ans

if __name__ == '__main__':
    solution = Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1])