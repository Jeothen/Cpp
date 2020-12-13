#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    ostringstream s;
    s << "ostring is " << 22 << "ZZ";
    const string result = s.str();
    cout << result << endl;
}
