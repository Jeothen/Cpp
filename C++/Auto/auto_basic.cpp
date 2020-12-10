#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <valarray>
using namespace std;


map<string, shared_ptr<int>> table;

auto mult(int c)
{
    /*  
    ==
    valarray <int> val = valarray<int>(1);
    return c * val;*/

    // valarray operator* Provide a proxy object referencing vavalarray
    // if return valarray<int>{1}; -> mult(1) == 1
    return c * valarray<int>{1};
}

struct lambda
{
    template <typename T>
    auto operator()(const T &arg) const
    {
        std::cout << arg << std::endl;
    }
};

template <typename T1, typename T2>
auto Add(const T1 &lhs, const T2 &rhs) -> decltype(lhs + rhs) { return lhs + rhs; }

auto main() -> int{
    map<string, shared_ptr<int>>::iterator i = table.find("test");
    // useful long variable type
    auto j = table.find("42");
    cout << typeid(j).name() << endl;
    
    //lambda
    auto f = [](int a) { cout << "lambda\n" << a << endl; };
    f(2);

    lambda print;
    print("operator test");


    auto myMap = map<int, float>();
    myMap.emplace(1, 3.14);

    // copy
    pair<int, float> const &firstPair = *myMap.begin();
    auto const &firstPair2 = *myMap.begin(); 
    cout <<firstPair.second << endl;
    cout <<firstPair2.second << endl;

    // not 3
    auto v = mult(3);
    cout << v[0] << endl; 
}