#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<std::string> vc = {"test1", "test2", "test3"};

    for (auto p : vc) // copy vc element,
    {
        std::cout << p << std::endl;
        p = "not_change_origin";  // so vector vc is not changed.
    }
    cout << "Reference" << endl;
    for (auto& p : vc)  // it refer to vc element
    {
        std::cout << p << std::endl;
        // so p = "x" -> vc is changed {"x","x","x"}
    }

    cout << "Const Reference" << endl;
    for (const auto& p : vc) // should not be edited, const reference
    {
        std::cout << p << std::endl;
    }
}