#include <iostream>
#include <string>
using namespace std;

class cls
{
public:
    // default
    cls(int data)
    {
        this->data = data;
    }
    // copy constructor
    cls(const cls &t)
    {
        data = t.data;
    }
    // assignment constructor
    cls &operator=(const cls &t)
    {
        data = t.data;
        return *this;
    }

    int data;
};

int main()
{
//  cls foo();   // error
    cls foo(2);  // default constructor
    cls foo2 = foo; //Copy Constructor Called

    cls foo3(3);
    foo3 = foo; //Assignment Constructor Called
    cout << foo.data << " " << foo2.data << " " << foo3.data << endl;
}