#include <iostream>
using namespace std;

struct Date // size :  (13+4+5) / 8 = 2.x == 3byte  >  short size (2byte),  so struct size is 3bytes
{
    unsigned short year : 13; // 2^13 = 8192,
    unsigned short month : 4; // 2^4 = 16
    unsigned short day : 5;   // 32
};

int main(){
    Date date;
    // if bit range is overed, compile error happens.
    date.year = 2020;
    date.month = 12;
    date.day = 25;

}