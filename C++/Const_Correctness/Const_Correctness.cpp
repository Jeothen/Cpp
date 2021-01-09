#include <iostream>

class C
{
    int x = 1;
    int arr[5];
public:
    int getX() const { return x; } // Function is const: Doesn't modify instance(x)
    int getX1() const;
    const int CgetX() const;
    void setX(int i) { x = i; }    // can modifies instance.

    // operator overload
    int &operator[](size_t index) { return arr[index]; }
    const int &operator[](size_t index) const { return arr[index]; }  // const instance
};

int C::getX1() const { return x; }
const int C::CgetX() const { return x; } // CgetX() type have to be const

struct Example {
    void foo() { std::cout << "Foo" << std::endl; }
    void foo() const { std::cout << "const Foo" << std::endl; }
};

// call basic method
void non_const_param(Example& a, Example* b)
{
    a.foo(); b->foo();
}

// call const method
void const_param(const Example& a, const Example *b)
{
    a.foo(); b->foo();
}

int main() {
    C test;
    std::cout << test.getX() << std::endl;
    test.setX(2);
    std::cout << test.getX1() << std::endl;
    std::cout << test.CgetX() << std::endl;

    Example a; Example b;
    non_const_param(a, &b);
    const_param(a, &b);
}