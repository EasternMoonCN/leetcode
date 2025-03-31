#include <deque>
#include <iostream>
using namespace std;




void my_push() {
    deque<int> deint;
    
    deint.push_back(1);
    deint.push_back(2);
    cout << deint.front() << endl;
    deint.pop_front();
    cout << deint.front() << endl;
    
}


int main() {
    my_push();
}