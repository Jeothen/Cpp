/*

typedef returnType (*name)(arguments);                      // All
using name = returnType (*)(arguments);                     // <= C++11
using name = std::add_pointer<returnType(arguments)>::type; // <= C++11
using name = std::add_pointer_t<returnType(arguments)>;     // <= C++14

*/

#include <iostream>
#include <type_traits>
#include <vector>

// classes with operator
struct Person
{
    std::string name;
    unsigned int age;
};

struct FindPersonByName
{
    FindPersonByName(const std::string &name) : _name(name) {}
    
    bool operator()(const Person &person) const
    {
        std::cout << "name = " << _name << std::endl;
        return person.name == _name;
    }
private:
    std::string _name;
};

bool foo() 
{
    printf("Call function\n");
    return true;
}

int main()
{
    // function pointer
    bool (*tmp)();
    tmp = foo;
    tmp();
    // upper c++17
    bool tmp2;
    tmp2 = std::invoke(foo);


    int i = 123; // int
    int& ri = i; // int  ri->i
    typedef std::add_pointer<decltype(i)>::type IntPtr; // int*
    typedef std::add_pointer<decltype(ri)>::type IntPtr2; // int*

    IntPtr pi = &i;
    std::cout << "i = " << i << "\n";
    std::cout << "*pi = " << *pi << "\n";    

    static_assert(std::is_pointer<IntPtr>::value, "IntPtr should be a pointer");
    static_assert(std::is_same<IntPtr, int *>::value, "IntPtr should be a pointer to int");
    static_assert(std::is_same<IntPtr2, IntPtr>::value, "IntPtr2 should be equal to IntPtr");

    typedef std::remove_pointer<IntPtr>::type IntAgain; // int
    IntAgain j = i; // int
    std::cout << "j = " << j << "\n";

    static_assert(!std::is_pointer<IntAgain>::value, "IntAgain should not be a pointer"); // int 
    static_assert(std::is_same<IntAgain, int>::value, "IntAgain should be equal to int");

    std::cout << "Class with operator()" << std::endl;

    std::vector<Person> vc;
    vc.push_back({"Foob",21});
    vc.push_back({"Foobar", 11});
    vc.push_back({"Foobar",111});
    std::vector<Person>::iterator iFind =
        std::find_if(vc.begin(), vc.end(), FindPersonByName("Foobar"));  // find_if called FindPersonByName()
}