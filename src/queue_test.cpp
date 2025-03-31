#include <queue>
#include <iostream>
using namespace std;




void my_push() {
    queue<int> qint;
    
    qint.push(1);
    qint.push(2);
    cout << qint.front() << endl;
    qint.pop();
    cout << qint.front() << endl;
    
}


int main() {
    my_push();
}