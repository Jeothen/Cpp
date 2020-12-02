#include <iostream>



int main(){
    struct alignas(4) S
    {
        char a;
        int b;
        int c;
    };
 
    struct alignas(8) S1  // value bigger than maximum size of element
    {
        char d;
        int e;
        int f;
    };

    std::cout << sizeof(S) << std::endl;  // 4byte alignment  4 (char + 3bytes padding)  4(int)   4 (int)
    std::cout << sizeof(S1) << std::endl;  // 8byte alignment  8 (char + 3bytes padding + int)   8 (int  + 4bytes padding)
}