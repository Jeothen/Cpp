#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
    char *name;
    int age;
public:
    Person(char const *new_name, int new_age)
        : name(new char[std::strlen(new_name) + 1]), age(new_age)
    {
        std::strcpy(name, new_name);
    }

    ~Person()
    {
        delete[] name;
    }

    // Copy constructor
    Person(Person const &other)
        : name(new char[std::strlen(other.name) + 1]), age(other.age)
    {
        cout << "p1 copy to p2, p2 created " << endl;
        std::strcpy(name, other.name);
    }
    // Copy constructor

    // Copy allocation constructor
    Person &operator=(Person const &other)
    {
        Person copy(other);
        swap(copy, *this);
        return *this;
    }
    // Copy allocation constructor
};



int main()
{
    Person p1("foo", 11);
    cout << "P1 Created" << endl;
    Person p2 = p1;   
} // end of main, p2 destructor called then delete p1 instance, and p1 desturctor called but p1 instance already deleted

