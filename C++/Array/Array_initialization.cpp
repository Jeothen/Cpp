#include <iostream>
using namespace std;

int main(){
    int arrayOfInts[5];  // 0, 0, 0, 0, 0
    int arrayOfInts2[5] = {10, 20, 30, 40, 50};
    int arrayOfInts3[] = {10, 20, 30/*test*/, 40, 50};
    int arrayOfInts4[5] = {10, 20}; // 10, 20, 0, 0, 0
    printf("%d\n",arrayOfInts3[2]); // not print remark

    char arrayOfChars[5]; // allocate the memory, but not initialization 
    printf("%d\n",arrayOfChars[0]);  // 14 - blank

}