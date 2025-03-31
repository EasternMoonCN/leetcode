#include <iostream>
using namespace std;

struct sdshdr8 {
    uint8_t len;
    uint8_t alloc;
    unsigned char flags;
    char buf[];
};

int main() {
    // cout << sizeof(sdshdr8) << endl;
    // cout << sizeof(uint8_t) << endl;
    // cout << sizeof(unsigned char) << endl;
    // char buf[9];
    // cout << sizeof(char*) << endl;
    // cout << sizeof(buf) << endl;
    // unsigned type;
    // cout << sizeof(unsigned ) << endl;
    // cout << sizeof(int) << endl;
    cout << (1L << 63) - 1 << endl;
    cout << LONG_MAX << endl;
}