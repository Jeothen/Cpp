#include <iostream>

namespace A
{
    struct Z  {  
        int a;
    };
    namespace I
    {
        void g(Z);
    }
    using namespace I;

    struct X
    {
        struct Y
        {
        };
        friend void f(Y) {}  // call f(X p)
    };
    void f(X p) { std::cout << "call f(X)" << std::endl;}
    void k(X::Y p) { std::cout << "call f(Y)" << std::endl;}
    void g(std::shared_ptr<X> p) { std::cout << "call g(ptr)" << std::endl;} // calling
} // namespace A


int main(){
    f(A::X()); // call f(X p)
    std::cout << 1 << std::endl;
    k(A::X::Y());
    std::cout << 2 << std::endl;
    g(std::make_shared<A::X>());
    std::cout << 3 << std::endl;
    // not using namespace in the other namespace
    h(A::Z()); // invalid: "using namespace I;" is ignored!  - h: not defined

}



// add reference

namespace A
{
    struct X;
    struct Y;
    void f(int);
    void g(X);
} // namespace A

namespace B
{
    void f(int i)
    {
        f(i); // calls B::f (endless recursion)
    }
    void g(A::X x)
    {
        g(x); // Error: ambiguous between B::g (ordinary lookup)
              //        and A::g (argument-dependent lookup)
    }
    void h(A::Y y)
    {
        h(y); // calls B::h (endless recursion): ADL examines the A namespace
              // but finds no A::h, so only B::h from ordinary lookup is used
    }
} // namespace B

// from "https://en.cppreference.com/w/cpp/language/adl"