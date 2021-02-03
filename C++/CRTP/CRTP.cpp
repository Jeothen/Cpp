#include <iterator>
#include <iostream>
#include <ostream>
using namespace std;

// CRTP
//---------------------General Form
template <class T>
struct base
{

};

struct derived : base<derived>
{

};

//---------------------static polymorphism

template <typename T>
struct base1
{
    void interface()
    {
        static_cast<T *>(this)->implementation(); // call
    }

    static void static_func()
    {
        T::static_sub_func();  // call
    }
};

struct derived1 : base1<derived1>
{
    void implementation();
    static void static_sub_func();
};

//---------------------object counter

template <typename T>
struct counter
{
    static inline int objects_created = 0;
    static inline int objects_alive = 0;

    counter()
    {
        ++objects_created;
        ++objects_alive;
    }

    counter(const counter &) 
    {
        ++objects_created;
        ++objects_alive;
    }

protected:
    ~counter() // just alive count down
    {
        --objects_alive;
    }
};

class X : counter<X>
{
public :
    void number_alive(){
        std::cout << objects_alive;
    }
};

class Y : counter<Y>
{
    
};

//---------------------polymorphic chaining

template <typename ConcretePrinter>
class Printer
{
public:
    Printer(ostream &pstream) : m_stream(pstream) {}

    template <typename T>
    ConcretePrinter &print(T &&t)
    {
        m_stream << t; // Hello
        return static_cast<ConcretePrinter &>(*this);
    }

    template <typename T>
    ConcretePrinter &println(T &&t)
    {
        m_stream << t << endl; // Printer!
        return static_cast<ConcretePrinter &>(*this);
    }

private:
    ostream &m_stream;
};

// Derived class
// The CRTP can be used to avoid such problem and to implement "Polymorphic chaining":
class CoutPrinter : public Printer<CoutPrinter>
{
public:
    CoutPrinter() : Printer(cout) {}

    CoutPrinter &SetConsoleColor()
    {
        return *this;
    }
};


//--------------------- polymorphic copy construction

class AbstractShape
{
public:
    virtual ~AbstractShape() = default;
    virtual std::unique_ptr<AbstractShape> clone() const = 0; // virtual function
};

// This CRTP class implements clone() for Derived
template <typename Derived>
class Shape : public AbstractShape
{
public:
    // define in the all derived class
    std::unique_ptr<AbstractShape> clone() const override // copy constructor by base class pointer
    {
        std::cout << "Copy Constructor !" << std::endl;
        return std::make_unique<Derived>(static_cast<Derived const &>(*this));  
    }
};

// Every derived class inherits from CRTP class instead of abstract class
class Square : public Shape<Square>
{
};

class Circle : public Shape<Circle>
{
};

int main(){

    // object count
    X create1;
    X* test;
    test->number_alive(); // 1

    //polymorphic chaining
    //  returns a 'Printer' instance.
    CoutPrinter().print("Hello ").SetConsoleColor().println("Printer!");

    
    Square a;
    a.clone(); // create copy constructor
}  
