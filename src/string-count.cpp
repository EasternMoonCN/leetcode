#include "utils/common.cpp"

class Solution
{
public:
    string toLowerCase(const string& str) {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
    vector<pair<string, int>> solve(vector<string> strs)
    {
        unordered_map<string, int> umap;
        
        for (string str : strs) {
            umap[toLowerCase(str)]++;
        }

        vector<pair<string, int>> results(umap.begin(), umap.end());
        sort(results.begin(), results.end(), [](pair<string, int> r1, pair<string, int> r2) -> bool {
            return r1.first < r2.first;
        });
        return results;
    }

};

int main() {
    vector<string> strs = {"ab", "a", "Ab"};
    vector<pair<string, int>> results = Solution().solve(strs);
    for (auto r : results) {
        cout << r.first << ", " << r.second << endl;
    }
}