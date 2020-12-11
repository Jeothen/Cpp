#include <iostream>
using namespace std;

int main(){
    // AND
    short a = 5;   // 0101
    short b = 11;  // 1011
    short c = a & b; // 0001
    cout << "5&11 = " << c << endl;  

    // OR
    a = 5;      // 0101
    b = 12;     // 1100
    c = a|b;    // 1101
    cout << "5|12 = " << c << endl;

    // XOR
    a = 5;      // 0101
    b = 12;     // 1100
    c = a^b;    // 1001
    cout << "5^12 = " << c << endl;

    // NOT
    a = 5;      //  00000000 00000101
    b = ~a;     //  11111111 11111010
    // 2bytes signed range  (-32767 ~ 32768)
    // first element is negative/positive sign
 
    // first bit sign is 
    cout << "signed range = " <<  b << endl;

    unsigned short d = 5;  // 00000000 00000101
    unsigned short e = ~d; // 11111111 11111010

    cout << "unsigned range = " <<  e << endl;
}   