
#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int arg;

public:
    Person() = default;
    ~Person() = default;
    Person(Person const &) = default;
    Person(Person &&) = default;
    Person &operator=(Person &&) = default;

    Person &operator=(const Person &other)
    {
        // self allocation protection
        if (this != &other)
        {
            cout << "not self allocation\n";
            return *this;
        }

        cout << "self allocation \n";
        return *this;
    }
};

int main()
{
    Person five;
    cout <<"same \n";
    // self allocation
    five = five;

    Person test;
    cout << "other\n";
    five = test;

}