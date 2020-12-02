#include <iostream>

int main()
{
    std::cout << alignof(int) << std::endl;

    struct  S
    {
        char c; // 1bytes 
        // 3bytes padding
        int a;  // 4bytes
        double b;  // 8bytes
    };
    std::cout << sizeof(S) << std::endl; // 4 + 8  + 4 (padding) = 16
    std::cout << alignof(S) << std::endl; // 8 - double

    // position
    std::cout << offsetof(S, c) << std::endl; // 0
    // there's a 3bytes padding between c and a
    std::cout << offsetof(S, a) << std::endl; // 4
    std::cout << offsetof(S, b) << std::endl; // 8

}