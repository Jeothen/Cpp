#include <iostream>

std::mutex a_mutex;
std::lock_guard<std::mutex> get_lock()
{
    return std::lock_guard<std::mutex>(a_mutex);
}

std::string foo()
{
    return std::string("ZZZ");
}

// If there are no copy extraction rules, always copying/moving
// but there are, the copyinh/moving constructor may or may not be called. Depends on implementation.

struct my_type
{
    my_type() = default;
    my_type(const int &) { std::cout << "Copying\n"; }
    my_type(int &&) { std::cout << "Moving\n"; }
};

my_type func()
{
    int b = 1;
    return my_type();  // default
    return my_type(2); // rvalue
    return my_type(b); // copying
}

/////////////------------------------

struct trivially_copyable
{
    int a;
};

void goo(trivially_copyable a) {} // not using a

int main()
{
    func();

    std::string str = std::string("foo"); // if variable same type as prvalue expression, copy elision

    std::string str1 = foo();

    goo(trivially_copyable{}); // parameter elision - prvalue expression
}