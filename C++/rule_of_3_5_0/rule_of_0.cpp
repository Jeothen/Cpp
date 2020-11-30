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
    Person &operator=(Person const &) = default;
    Person &operator=(Person &&) = default;

};
struct Person2
{
    string name;
    int arg;
};

int main(){
    Person five;
    Person2 zero;

}