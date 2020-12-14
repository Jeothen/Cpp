#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
    std::vector<int> v = {1, 2, 3, 4};
    // print without explicit loop
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " : "));
    std::cout << std::endl;

    // ostream_iterator allows container's content type implicitly.
    int n = 3;
    // std::cout <-  fixed floating point n digits
    std::cout << std::setprecision(n);
    std::fixed(std::cout);
    std::cout <<"Loop print" << std::endl;
    std::vector<int> vc = {1, 2, 3, 4};
    for (auto& p : vc) std::cout << p << " : ";
    std::cout << std::endl;
    std::cout << "Ostream iterator implictly affected" << std::endl;
     // ostream_iterator
    std::copy(vc.begin(), vc.end(), std::ostream_iterator<float>(std::cout, " : "));

    
    std::cout << "TransForm" << std::endl;

    std::vector<int> vc2 = {1, 2, 3, 4, 8, 16};
    std::boolalpha(std::cout); // print booleans alphabetically
    std::transform(vc2.begin(), vc2.end(), std::ostream_iterator<bool>(std::cout, " ! "), 
    [](int val) {
        return (val % 2) == 0;
    });
    std::cout << std::endl;
    // square same as
    std::transform(vc2.begin(), vc2.end(), std::ostream_iterator<int>(std::cout, " "),
    [](int val) {
        return val * val;
    });

    std::cout << std::endl;
    // generator
    std::cout << "Generate rand" << std::endl;
    const int N = 10;
    std::generate_n(std::ostream_iterator<short>(std::cout, " "), N, std::rand);
    std::cout << std::endl;
    // array
    std::cout << "array same as vector" << std::endl;
    int arr[] = {1, 2, 3, 4, 8, 16};
    std::transform(arr, std::end(arr), std::ostream_iterator<int>(std::cout, " ,"),
    [](int val) {
        return val * val;
    });
    std::cout << std::endl;
}
