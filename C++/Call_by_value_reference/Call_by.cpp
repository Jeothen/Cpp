#include <iostream>
using namespace std;

void value(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}

void reference(int& a, int& b){
    int tmp = a;
    a =b;
    b = tmp;
}

int main(){
    int a = 10, b = 20;
    value(a,b);
    cout << "call by value\n";
    cout << a << " " << b << endl;

    reference(a,b);
    cout << "call by reference\n";
    cout << a << " " << b << endl;
}