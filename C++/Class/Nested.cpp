#include <iostream>

// inner to outer
class Outer
{
    struct Inner
    {
        int get_sizeof_x()
        {
            return sizeof(x); // Legal(C++11): x is not evaluated, so no instance is required
        }

        int get_x()
        {
//            return x; // without an instance this is illegal. if x is static member, it's legal.
            return 0;
        }

        int get_x(const Outer& o)
        {
            return o.x; // Legal (C++11): As a member of Outer, Inner can access private members of outer.
        }
    };
    int x;
};

// converse
// outer to inner

class Outer2
{
    class Inner2
    {
        int pri;
        public :
            int pub;
    };
    Inner2 in;

public:
    int get_pri()
    {
//        return in.pri; // Error: int Outer2::Inner2::pri is private.
        return 0;
    }
    int get_pub()
    {
        return in.pub;
    }
};

class Outer3{
    struct Inner3 { // private
        void foo() { printf("foo\n"); }
    };
public :
    static Inner3 Inner3_goo() { printf("Goo\n"); return Inner3();} //
    class Inner4_ {};
};

typedef Outer3::Inner4_ IO;  // public


//derived from nested class
class BaseOuter
{
    struct BaseInner_
    {
        void do_something() {printf("Base Something\n");}
        virtual void do_something_else();
    } b_in;

public:
    typedef BaseInner_ Inner;
    virtual ~BaseOuter() = default;
    virtual Inner &getInner() { return b_in; } // BaseInner_
};

void BaseOuter::BaseInner_::do_something_else() { printf("Base Something else\n"); } // virtual method - can be overrided by derived class

class DerivedOuter : public BaseOuter
{
    // Note the use of the qualified typedef; BaseOuter::BaseInner_ is private.
    struct DerivedInner_ : BaseOuter::Inner
    {
//        void do_something() override {} // this is not virtual 
        void do_something_else() override;
    } d_in;

public:
    typedef DerivedInner_ Inner;

    BaseOuter::Inner &getInner() override { return d_in; } // DerivedInner_
};

void DerivedOuter::DerivedInner_::do_something_else() { printf("Derived Something else\n"); }

int main() {
//    Outer3::Inner3  test  // is private
    auto test = Outer3::Inner3_goo();  // Inner3
    printf("\n");
    test.foo();
    printf("\n");
    Outer3::Inner3_goo().foo();
    printf("\n");

    // derived from nested class
//    BaseOuter::BaseInner_::do_something();  // non-static  / BaseInner_ is private
//    BaseOuter::Inner::do_something_else();  // non-static  / Inner is public
    BaseOuter *b = new BaseOuter;
    BaseOuter::Inner &bin = b->getInner();
    bin.do_something();
    b->getInner().do_something();

//    DerivedOuter::DerivedInner_::do_something(); non-static->instace / private
    BaseOuter *d = new DerivedOuter;
    BaseOuter::Inner &din = d->getInner();  // Derived_Inner
    din.do_something();  // not override
    d->getInner().do_something_else();  // override
}