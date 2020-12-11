#include <bitset>
#include <iostream>
using namespace std;


template <typename T>
T rightmostSetBitRemoved(T n)
{
    // 0xxxx11100   & 0xxxx11011 ==>  0xxxx11000  (most right 1 bit set 0)
    return n & (n - 1);
}


int main(){
    std::bitset<5> num(std::string("011001"));
    cout << num << endl;
    num.set(0);       // 01101
    cout << num << endl;
    num.set(2);       // 01101
    cout << num << endl;
    num.set(4, true); // 11101
    cout << num << endl;

    cout << endl <<  "reset" << endl;
    num.reset(0);      // 11100
    cout << num << endl;
    num.reset(1);      // 11100
    cout << num << endl;
    num.set(3, false); // 10100
    cout << num << endl;

    cout << endl << "flip" << endl;
    num.flip(2); // 10000
    cout << num << endl;
    num.flip(0); // 10001
    cout << num << endl;
    num.flip();  // 01110
    cout << num << endl;

    cout << "All set bit manipulate" << endl;
    num.set(); // 11111
    cout << num << endl;
    num.reset();
    cout << num << endl;
    num = -1; // 111111111b
    cout << num << endl;

    unsigned value = 1022;  // 11 1111 1110
    unsigned bits = 0; // accumulates the total number of bits set in `n`

    for (bits = 0; value; value >>= 1) 
        bits += value & 1;
    cout << bits << endl;

    value = 1021;  // 1111111101
    for (bits = 0; value; ++bits)
        value &= value - 1; // remove most right bit 1

    cout << bits << endl;


    // power of 2 is n & (n-1) == 0  // 10000  1111 -> 0
    int n = 16;
    bool power_of_2 = n && !(n & (n - 1)); // n&& -> if n == 0
    cout << power_of_2 << endl;
}