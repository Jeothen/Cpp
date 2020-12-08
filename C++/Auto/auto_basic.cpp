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
    return c * valarray<int>{1};
}

int main(){
    map<string, shared_ptr<int>>::iterator i = table.find("test");
    // useful long variable type
    auto j = table.find("42");
    cout << typeid(j).name() << endl;

    // loop
    vector<int> vc = {0, 1, 2, 3, 4, 5};
    for (auto& p : vc){
        cout << p << ' ';
        p = 1;
    }

    //lambda
    auto f = [](int a) { cout << "lambda\n" << a << endl; };
    f(2);

    auto myMap = map<int, float>();
    myMap.emplace(1, 3.14);

    // copy
    pair<int, float> const &firstPair = *myMap.begin();
    auto const &firstPair2 = *myMap.begin(); 
    cout <<firstPair.second << endl;
    cout <<firstPair2.second << endl;

    // template

    auto v = mult(3);
    cout << v[0] << endl; // some value that could be, but almost certainly is not, 3.
}