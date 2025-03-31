#include "../utils/common.cpp"
/**
 * 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。
 */

class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> results;
        vector<bool> visited(S.size(), false);
        backTrack(S, "", results, visited);
        return results;
    }

    void backTrack(string s, string result, vector<string>& results, vector<bool> visited) {
        if (s.size() == result.size()) {
            results.push_back(result);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            result.push_back(s[i]);
            visited[i] = true;
            backTrack(s, result, results, visited);
            visited[i] = false;
            result.pop_back();
        }
    }
};

int main() {
    common<string>::printVector(Solution().permutation("qwe"));
    return 0;
}
