#include <iostream>

class Test
{
private:
    double a;
    double b;

public:
    Test(double pa, double pb) { a = pa; b = pb;}
    friend void print(Test animal);
    friend class foo;
};

void print(Test str)
{
    std::cout << "a = " << str.a << std::endl;
}

class foo
{
public:
    void goo(const Test& str)
    {
        std::cout << str.a << ", " << str.b << std::endl;
    }
};

class B {};

int main()
{
    Test t = {10,100};
    print(t);
    foo f;
    f.goo(t);
}