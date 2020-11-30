#include <iostream>
using namespace std;

// N factorial 

template <int N>
struct Factorial
{
    static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1>
{
    static const int result = 1;
};

/*-------------------------------------------------------*/
// positive

template <int N, unsigned int exponent>
struct power
{
    static const int halfvalue = power<N, exponent / 2>::value; // 20 -> 10 -> 5 ...
    static const int value = halfvalue * halfvalue * power<N, exponent % 2>::value; 
};

// init
template <int N>
struct power<N, 0>
{
    static const int value = 1;
    static_assert(N != 0, "power<0, 0> is not allowed"); // alarm
};

template <int N>
struct power<N, 1>
{
    static const int value = N;
};

/*-------------------------------------------------------*/
// negative - C++14

template <int N, int exponent>
struct powerDouble
{
    static const int exponentAbs = exponent < 0 ? (-exponent) : exponent;  // negative -> positive
    static const int halfvalue = powerDouble<N, exponentAbs / 2>::intermediateValue; 
    static const int intermediateValue = halfvalue * halfvalue * powerDouble<N, exponentAbs % 2>::intermediateValue;

    constexpr static double value = exponent < 0 ? (1.0 / intermediateValue) : intermediateValue;
};

// init
template <int N>
struct powerDouble<N, 0>
{
    static const int intermediateValue = 1;
    constexpr static double value = 1;
    static_assert(N != 0, "powerDouble<0, 0> is not allowed");
};

template <int N>
struct powerDouble<N, 1>
{
    static const int intermediateValue = N;
    constexpr static double value = N;
};

int main()
{
    std::cout << "3! : 3*2*1 = " << Factorial<3>::result << std::endl;

    std::cout << power<2, 20>::value << endl;// 2^20
    // C++ 14
    std::cout << powerDouble<2, -5>::value << endl;;

}
