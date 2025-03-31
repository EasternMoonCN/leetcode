#include "utils/common.cpp"

struct my_struct {
    /**
     * 如果我们要根据某个属性对对象进行升序排序，那么比较函数应该在第一个对象的属性小于第二个对象的属性时返回 true
     */
    bool operator()(pair<int, int>&a, pair<int, int>& b) {
        return a.first + a.second > b.first + b.second;
    }
};

class my_class {
    public:
    bool operator()(pair<int, int>&a, pair<int, int>& b) {
        return a.first + a.second > b.first + b.second;
    }
};

bool my_function(pair<int, int>a, pair<int, int> b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    priority_queue<int, vector<int>, less<int>> pq;
    pq.push(3);
    pq.push(5);
    pq.push(1);

    cout << pq.top();
    pq.pop();

    cout << pq.top();
    pq.pop();
    cout << pq.top() << endl;

    less<int> ls;
    cout << ls(1, 2) << endl;

    vector<int> nums1 = {1, 2, 3}, nums2 = {4, 5, 6};
    auto my_lamda = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
                return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
            };
    // https://blog.csdn.net/lyx200154/article/details/137119139
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(my_lamda)> dpcmp(my_lamda);
    priority_queue<pair<int, int>, vector<pair<int, int>>, my_struct> dpstruct;
    priority_queue<pair<int, int>, vector<pair<int, int>>, my_class> dpclass;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&my_function)> dpfunction(my_function);

    // 函数指针
    bool (*function_point)(pair<int, int>, pair<int, int>) = my_function;
    cout << function_point({1, 2}, {3, 4}) << endl;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(function_point)> dpfunctionpoint(function_point);

    vector<int> nums = { 3, 2, 4, 5};
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    common<int>::printVector(nums);
    return 0;


}