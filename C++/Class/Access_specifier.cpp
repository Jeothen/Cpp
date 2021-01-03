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


// Accessing member func / var
struct Test
{
    int a;
    static int sa;
    void change_sa(int a){
       sa = a;
    }
    
    Test(){
        a = 1;
        sa = 1;
    }
};
// Accessing static member
// static member shares all objects of classs
int Test::sa;

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

    // Accessing static member
    Test tmp;
    Test tmp2;
    Test* ptr = &tmp; // pointer to ref.
    Test::sa = 3;
    std::cout << "tmp.sa = " << tmp.sa << std::endl;    
    tmp.change_sa(5);
    std::cout << "tmp.sa = " << tmp.sa << std::endl;
    ptr->change_sa(6);
    std::cout << "tmp.sa = " << tmp.sa << std::endl;
    (*ptr).change_sa(7);
    std::cout << "tmp.sa = " << tmp.sa << std::endl;
    std::cout << "tmp2 .sa = " << tmp2.sa << std::endl;
}