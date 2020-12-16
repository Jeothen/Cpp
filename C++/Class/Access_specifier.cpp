#include <iostream>


// class vs struct
struct MyStruct
{
    int x; // x is public
};
class MyClass
{
    int x; // x is private
public:
    int f()  const noexcept { return m_x;}
    void g(int const x) noexcept { m_x = x;}
    
private:
    int m_x;
};

// using struct like class
struct P_struct
{
    int calculateValue() noexcept { return value() + 2; } // When C_struct, value() overrided 40

protected:
    virtual int value() noexcept = 0;
};

struct C_struct : P_struct // inheritance
{
protected:
    int value() noexcept final override { return 40; } 
};

auto main() -> int
{
    MyStruct s;
    s.x = 9;

    MyClass c;
 //   c.x = 9;  // private
    c.g(2);
    std::cout <<  c.f() << std::endl;

    C_struct test;
    std::cout << test.calculateValue() << std::endl; // P_struct public function
}