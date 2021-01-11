#include <iostream>

class C
{
    int x = 1;
    int arr[5];
    mutable int cache = 3;
public:
    C() {}
    int getX() const { return x; } // Function is const: Doesn't modify instance(x)
    int getX1() const;
    const int CgetX() const;
    void setX(int i) { x = i;};    // can modifies instance.
    void setX1(const int& i) { x= i;}
    void set_cash(int i) const {cache = i;}
    // operator overload  - matching keyword
    int &operator[](size_t index) { return arr[index]; }
    const int &operator[](size_t index) const { return arr[index]; }  // const instance
};

int C::getX1() const { return x; }
const int C::CgetX() const { return x; } // CgetX() type have to be const

struct Example {
    void foo() { std::cout << "Foo" << std::endl; }
    void foo() const { std::cout << "const Foo" << std::endl; }
//    const int x1 = getX1();    // getX1 is not const function
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

void test_fun(const int& a, const int b)
{
    std::cout << a << " " << b << std::endl;
    return;
}

int main() {
    C test;
//    C::setX(k); // Cannot be accessed without create instance (not static function)
    std::cout << test.getX() << std::endl;
    test.setX(2);
    std::cout << test.getX1() << std::endl;
    std::cout << test.CgetX() << std::endl;

    Example a; Example b;
    non_const_param(a, &b);
    const_param(a, &b);

    int n1 = 1, n2 = 2;
    test_fun(n1,n2); // int passed to const int or const int& parameter

    // mutable keyword
    C ncon;
    ncon.setX(2);
    ncon.set_cash(2);

    const C con;  // if not initialized, error occured when compile time - constructor should be implemented.
    con.set_cash(2);
    
}   