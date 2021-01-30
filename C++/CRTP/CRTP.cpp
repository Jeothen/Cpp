#include <iterator>

// CRTP
// General Form 
template <class T>
struct base
{
    // ...
};
struct derived : base<derived>
{
    // ...
};

// static polymorphism

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

//