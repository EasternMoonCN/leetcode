#include "utils/common.cpp"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> qs;
        vector<bool> visited(wordList.size(), false);
        qs.push(beginWord);
        int lenght = 0;
        while(!qs.empty()) {
            int size = qs.size();
            lenght++;
            // 与上一个相似个数
            for (int i = 0; i < size; ++i) {
                string curr = qs.front(); qs.pop();
                // 已找到终点
                if (curr == endWord) {
                    return lenght;
                }
                for (int i = 0; i < wordList.size(); ++i) {
                    // 已访问过
                    if (visited[i]) {
                        continue;
                    }
                    if (isSimilar(curr, wordList[i])) {
                        visited[i] = true;
                        qs.push(wordList[i]);
                    }
                }
            }
        }
        return 0;
    }

    bool isSimilar(string s1, string s2) {
        int n = s1.size(), num = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++num;
            }
        }
        return num == 1;
    }
};
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
}