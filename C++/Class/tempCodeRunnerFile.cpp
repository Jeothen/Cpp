#include <iostream>
using namespace std;

/*
struct A
{
public: // everyone
    int p1;
protected: // derived and friend and itself  
    int p2;
private: // friend and itself
    int p3;
};

// derived class/struct access to publoc and protected

struct B : public A  // == struct B : A   default - B : (struct - public / class - private)
{   
    void f(){
        p1 = 4;  // public in B
        p2 = 5;  // protected in B
        p3 = 6;  // private in A  / not accessible
    }
};

struct C : private A  
{
    void f(){
        p1 = 4; // private in B
        p2 = 5; // private in B
        p3 = 6; // private in A / not accessible
    }
};

struct D : protected A 
{
    void f()
    {
        p1 = 4; // protected in B
        p2 = 5; // protected in B
        p3 = 6; // private in A / not accessible
    }
};
*/

class P {
public:
    int move();
    int turn();
};

class PCh : private P {
public:
    using P::move;
private:
    using P::turn;
};

class Ch : public P 
{
public :
    using P::move;
private :
    using P::turn;
};

int main(){
    // outside class/struct
/*
    B test; 
    test.p1 = 1; // public
    test.p2 = 2; // protected
    test.p3 = 3; // X

    C test1; 
    test1.p1 = 1; // private
    test1.p2 = 2; // private
    test1.p3 = 3; // X

    D test2;
    test2.p1 = 1; // protected
    test2.p2 = 2; // protected
    test2.p3 = 3; // X
*/
    // private
/*    PCh pchild;
    pchild.move();  // compile error
    pchild.turn(); // not accessible error
    P pcasting = static_cast<P&>(pchild); // private inheritance not access base method
       

*/
    Ch child;
//    child.move();   // compile error
//    child.turn();  //
    P casting = static_cast<P&>(child); // public inheritance
    casting.move();

    


}