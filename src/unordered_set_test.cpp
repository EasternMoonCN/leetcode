#include <unordered_set>
#include <iostream>
using namespace std;


void my_return() {
    unordered_set<int> uset;
    uset.insert(1);
    auto e = uset.insert(1);
}

void my_insert() {
    unordered_set<int> uset;
    uset.insert(1);
    uset.insert(2);
    auto it = uset.find(1);
    cout << (it == uset.end());
}

void my_count() {
    unordered_set<int> uset;
    uset.insert(1);
    uset.insert(2);
    cout << uset.count(1);
}

void my_init() {
    unordered_set<int> uset = {};
    uset.insert(1);
    cout << *uset.begin();
}

void my_size() {
    unordered_set<int> uset = {};
    uset.insert(1);
    cout << uset.size() << endl;
}

void my_erase() {
    unordered_set<int> uset;
    uset.insert(1);
    uset.insert(2);
    uset.erase(1);
    cout << uset.count(1);
}
int main() {
    // my_insert();
    // my_count();
    // my_init();
    // my_erase();
    my_size();
    cout << max(1, 2) << endl;
}

