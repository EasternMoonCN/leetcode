#include <string>
#include <iostream>
using namespace std;

string my_reverse(string s) {
    // reverse(s.begin(), s.end());
    // string res(s.size(), ' ');
    string res;
    res.reserve(s.size());
    reverse_copy(s.begin(), s.end(), res.begin());
    return res;
}

void my_split() {
    string r = "1:1";
    auto it = r.find(':');
    string r1 = r.substr(0, it);
    string r2 = r.substr(it + 1);
    cout << r1 << "," << r2 << endl;
}

void my_toint() {
    string s = "123";
    int i = stoi(s);
    cout << i << endl;
}

int main() {
    // cout << my_reverse("abc");
    // my_split();
    my_toint();
    return 0;
}

