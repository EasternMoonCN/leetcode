from functools import cache
from typing import List
class Solution:
    # 如何进行分割：1. 不同字符必须分割，2.连续字符可分可不分
    def countTexts(self, pressedKeys: str) -> int:
        n = len(pressedKeys)
        mod = 1000000007
        # 长度为i字符的分割次数
        @cache
        def dfs(i: int, j: int, path: str)-> int:
            if i == 0:
                print(path + "," + pressedKeys[i: j + 1])
                return 1
            # 分
            r = dfs(i - 1, i - 1, path +  "," + pressedKeys[i: j + 1])
            # 不分
            # 检查是否可不分
            if i > 0 and pressedKeys[i - 1] == pressedKeys[j]:
                r += dfs(i - 1, j, path)
            return r
        return dfs(n - 1, n - 1, "") % mod
if __name__ == '__main__':
    pressedKeys = "22233"
    print(Solution().countTexts(pressedKeys))