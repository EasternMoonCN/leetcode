#include <vector>
// #include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    vector<int> nums;
    cout << nums.empty();
    nums.push_back(0);
    cout << nums[0];
    sort(nums.begin(), nums.end());
    cout << accumulate();
    return 0;
}