#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    std::cout << "Reading File" << std::endl;
    ifstream ifs("test.txt");
    std::vector<char> vc(100);
    std::copy(std::istream_iterator<char>(ifs), std::istream_iterator<char>(), vc.begin() /*std::back_inserter(vc)*/);
    for (auto p: vc) std::cout << p;
    std::cout << std::endl;

    std::cout << "Parsing Test" << std::endl;
    ifstream ifs2("Parsing_test.txt");
    int i; double d; short st; std::string s;
    while(ifs2>> i >> d >> st >> s){
        std::cout << i << " " << d << " " << st << " " << s << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Transform" << std::endl;
    ifstream ifs3("double_test.txt");
    std::vector<double> vd(20);
    // if ifs3's element doesn't construct by int, there isn't corectly operated. calculate to first start of different type.
    std::transform(std::istream_iterator<int>(ifs3), std::istream_iterator<int>(), vd.begin(),
    [](int val) {
        return val * 3.14;
    });
    for (auto p:vd) std::cout <<p << " ";
}