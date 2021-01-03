#include <iostream>

struct A
{
    int m;
    A(int num)
    {
        std::cout << num << std::endl;
        m = num;
    }
};

struct B : virtual A
{
    B() : A(5) {}
};

struct C : virtual A
{
    C() : A(4) {}
};

struct D : B, C // B, C derived from virtual A
{
    D() : A(3) {} // Since A is inherited as virtual, it exists as an instance
    // if A is not derived as virtual, using like
    // D() : B::A(4)
};

void f()
{
    D object; 
}

int main(){
    f();
}