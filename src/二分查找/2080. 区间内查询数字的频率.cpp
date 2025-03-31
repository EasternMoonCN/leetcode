#include "../utils/common.h"

class RangeFreqQuery {
public:
    // vector<int> arr;
    // RangeFreqQuery(vector<int>& arr) {
    //     this->arr = arr;
    // }

    // int query(int left, int right, int value) {
    //     vector<int> copyArr(arr.begin() + left, arr.begin() + right + 1);
    //     sort(copyArr.begin(), copyArr.end());

    //     int lowPos = lower_bound(copyArr, value);
    //     // if (lowPos == copyArr.size()) {
    //     //     return 0;
    //     // }
    //     int upperPos = lower_bound(copyArr, value + 1);
    //     return upperPos - lowPos;
    // }

    // int lower_bound(vector<int> copyArr, int target) {
    //     int left = 0, right = copyArr.size() - 1;
    //     while (left <= right) {
    //         int mid = (left + right) / 2;
    //         if (copyArr[mid] < target) {
    //             left = mid + 1;
    //         } else {
    //             right = mid - 1;
    //         }
    //     }
    //     return left;
    // }
    

    // 相同元素下标，下标递增
    unordered_map<int, vector<int>> umap;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            umap[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto it = umap.find(value);
        if (it == umap.end()) {
            return 0;
        }
        // vector<int> nums = it->second;
        // >= left
        auto lowPos = lower_bound(it->second.begin(), it->second.end(), left);
        // > right
        auto upPos = upper_bound(it->second.begin(), it->second.end(), right);
        return upPos - lowPos;
    }

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

int main() {
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery* obj = new RangeFreqQuery(arr);
    cout << obj->query(1, 2, 4) << endl;
    delete obj;
    return 0;
}