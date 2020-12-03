#include <stddef.h> // size_t, ptrdiff_t

using Size = ptrdiff_t;  // difference between two pointer

template <class test_class, size_t N>
// C++11
constexpr auto N_items(test_class (&)[N]) noexcept -> Size  
{
    return N;
}

#include <iostream>
using namespace std;
auto main() -> int  // wow...
{
    int const a[] = {1,2,3,4,5,6,7,8,9,10};
    Size const n = N_items(a);
    int b[n] = {}; // An array of the same size as a.
    cout << "Size = " << n << "\n";
    cout << "Array b size  = " << sizeof(b) / sizeof(int) << endl;

    const auto test_size = std::extent<decltype(b)>::value; // c++11
    cout << test_size << endl;

    // c++17
    // std::size
}