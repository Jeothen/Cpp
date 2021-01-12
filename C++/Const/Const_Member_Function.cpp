#include <iostream>
#include <map>
#include <string>
using namespace std;

class A
{
public:
    map<string, string> *mapOfStrings;
    int v;
    int* ptr;
public:
    A()
    {
        mapOfStrings = new map<string, string>();
        ptr = new int;
    }

    void insertEntry(string const &key, string const &value) const // const member function
    {
        //  it can be modified indirectly using a pointer.
        (*mapOfStrings)[key] = value;
        delete mapOfStrings;
        // can't do an assignment on a class data member
        mapOfStrings = new map<string, string>();
        v = value;
    }

    void refresh(string const &key, string const &value)
    {
        (*mapOfStrings)[key] = value;
        delete mapOfStrings;
        mapOfStrings = new map<string, string>(); 
        v = 0;
    }
    void getEntry(string const &key) const
    {
        // this is not assignment
        cout << mapOfStrings->at(key);
    }
};

int main(int argc, char *argv[])
{

    A var;
    var.insertEntry("abc", "abcValue");
    var.getEntry("abc");
    getchar();
    return 0;
}