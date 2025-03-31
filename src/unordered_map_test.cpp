#include "utils/common.h"

void fore() {
    unordered_map<int, int> umap;
    umap.insert({1, 1});
    umap[2] = 2;
    for (auto it = umap.begin(); it != umap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << umap[3];

}

void sort() {

}

int main() {
    
    // unordered_map<int, vector<pair<int, int>>> umap;
    // umap[0].push_back({0, 0});
    // cout << umap[0][0].first;
    // umap[0].push_back({1, 1});
    // cout << umap[0][1].first;

    // fore();
    return 0;
}

void test1() {
    unordered_map<int, int> imap;
    imap[1] = 3;
    imap.insert({2, 2});

    // 判断是否存在键
    cout << imap.count(1) << endl;
    cout << imap.count(0) << endl;

    vector<vector<int>> res(3);

    // res[0].push_back(make_pair(1, 1));

    // for (auto entry : imap) {
    //     cout << entry.first +  " " + entry.second << endl;
    // }

    
}