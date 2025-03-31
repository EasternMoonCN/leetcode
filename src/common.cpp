#include <iostream>
#include <string>
using namespace std;


string num2string(int n) {
    // 数字转字符串
    return to_string(n);
}

int string2num(string s) {
    return stoi(s);
}

void vectortest() {
    vector<int> nums;
    nums.push_back(2);
    nums.pop_back();
}

void stringtest() {
    string s1(4, '0'), s2 = "12345";
    cout << s1 << endl;
    cout << s1 + s2 << endl;
}

void powtest() {
    cout << pow(10, 7) << endl;
    long long total = 10;
    cout << total % 2 << endl;
}


// 返回 第一个 大于或等于 val 的元素的迭代器。
void lowerboundtest() {
    vector<int> nums = {10, 20, 20, 30, 30};
    auto it = lower_bound(nums.begin(), nums.end(), 21);
    cout << it - nums.begin() << endl;
    cout << *it;
}

// 返回 第一个 大于 val 的元素的迭代器。
void upperboundtest() {
    vector<int> nums = {10, 20, 20, 30, 30};
    auto it = upper_bound(nums.begin(), nums.end(), 20);
    cout << it - nums.begin() << endl;
    cout << *it;
}


int main() {
    // stringtest();
    // powtest();
    lowerboundtest();
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    int n = 9;
    cout << sqrt(n) << endl;
    return 0;
}