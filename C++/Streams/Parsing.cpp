#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    ostringstream s;
    s << "ostring is " << 22;
    const string result = s.str();
    cout << result << endl;
}