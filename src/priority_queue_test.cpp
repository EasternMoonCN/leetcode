#include <queue>
#include <iostream>
using namespace std;


bool cmp1 (int a, int b) {
    return a > b;
}

void my_order1() {
    priority_queue<int, vector<int>, bool(*)(int, int)> pq(cmp1);
    pq.push(5);
    pq.push(1);
    pq.push(3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void my_order2() {
    auto cmp2 = [](int a, int b) -> bool {
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(cmp2)> pq(cmp2);
    pq.push(5);
    pq.push(1);
    pq.push(3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}


int main() {
    my_order2();
}