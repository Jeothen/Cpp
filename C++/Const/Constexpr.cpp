#include <iostream>
using namespace std;

constexpr int sum(int a, int b) { // compile time
    return a+b;
}



constexpr int sum1(int a, int b){  // compile time
    int a1 = a; // runtime   - when using a1, error occured
    cout << "a1 = " << a1 << endl;  
    return a+b;
}

// if compile time function needed, implement needed
constexpr int ABS(int a){
    return a > 0 ? a : -a;
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

    constexpr int S = sum(20,30); // compile time
    int array[S]; 
    int array1[sum(20,30)]; // compile time

    int a = 20;
    constexpr auto summary = sum(a, abs(-20));  // constexpr is compile time ,  abs() and a is runtime
    printf("%d\n",sum1(10,20));


    // if constexpr  - above c++17
    if constexpr (true){

    }
      

}