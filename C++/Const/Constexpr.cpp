#include <iostream>
using namespace std;

constexpr int sum(int a, int b) {
    return a+b;
}


int main(){
    constexpr int n = 1 + 2; // compile time constant - cannot be edited
    cout << n * 2 << endl;


    // const can be either a compilation constant or a runtime constant 
    const int n1 = 10;
    const int n2 = abs(10);  // it determined at runtime

    int arr1[n1]; 
    int arr2[n2]; // array size must be determined at compile time  - almost compiler may be failed
    cout << n1 << n2 << endl;

    constexpr int n3 = abs(10); // it must be compilation constant - so error occured
    constexpr int n4 = 10;

    constexpr auto domain = ".COM"; // constexpr char*  <- const char * const - old version
    constexpr auto PI = 3.14;       // constexpr double


}