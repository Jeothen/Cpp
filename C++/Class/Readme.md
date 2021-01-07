### Class vs struct

* The difference from struct

  * default, member variable, member function.

  * base classes

    * struct is public / class is  private.

  * Class has a constructor and destructor, enforcing invariant

  * Struct just simple collection of values.

  * Class can be used to declare template parameters

    

  * In C++, struct and class have no distinction except for the above difference.

#### Static member

* A variable or function shared by all instances in a class

* Even const instances can perform static variable initialization, but static const / constexpr member initialization must be performed in struct/class.

* Since there is no this pointer in a static member function, the instance is used as a parameter to access the static member variable. /  Since there is no this pointer, the address is stored as a pointer to a normal function, not member function.

  * ```c++
    class c {
        int n;
      public:
        c() : n(0) {} // initialize
    //    static void bad_mutate() { ++n *= 5; }  		// there's no this pointer
        static void good_mutate(c &e) { ++e.n &= 5; }
      	static void foo();
    };
    
    // typedef void (c::*member_f_ptr)();  there's no this pointer.
    typedef void (*f_ptr)();
    f_ptr s = &c::foo;
    ```

* regardless of existance of instance, static member created at program start time.



#### Non-static member

* Member variable/function that only works in each instance

* Member functions can be called in normal / rvalue instances.

  * ```c++
    struct S {
        void normal() &  {} // normal instances.
        void rval() && {} // rvalue (temporary) instances.
    };
    
    S ins;
    ins.func();     // called normal instance
    S{}.func(); 		// Called rvalue instance
    ```



---

# Class

* Access Specifiers

  * public : Everyone
  * protected : class itself and derived clasees and friend classes.
  * private : class itself and friend classes
* If static member variable is declared as global variable, Can be accessed from any instance of class(struct)



* Friend specifiers
  * Using the friend specifier within a class allows access to global function or other classes(methods)



### Inheritance

* Class / Struct has a Inheritance,  and there's private / public / protected inheritance
  * public inheritance
    * public member of base class - public member of derived class
    * protected member of base class - protected member derived class
    * Private member of base class - never access directly from a derived class / access through call public / protected
  * protected inheritance
    * public / protected member of base class - protected member of derived class
    * Private member of base class - never access directly from a derived class / access through call public / protected
  * private inheritance
    * public / protected member of base class - private member of derived class
    * Private member of base class - never access directly from a derived class / access through call public / protected
    
    
  
* In private inheritance, private methods of base class cannot be accessed.

* In public inheritance, private methods of base class can be accessed by type casting



* final class
  * A class containing the final specifier can be derived from another class, but cannot be the base class of other class.



### Virtual Inheritance

* If inherited as a private/public class (struct) rather than a virtual class (struct), it may be ambiguous.

  * For example, when there is an inheritance relationship of A->B / A->C and an inheritance relationship of B->D / C->D, 

     In D, A's constructor is called twice.  

  * And, When accessing A from D, it is unclear whether to access A instance created in B or C.

* So, When inheriting multiple classes (struct), make diamond diagrams form through virtual

  * In the case of A->B / A->C through virtual, B and C share and use one instance of A together.



### Nested Class/Struct

* Define class/struct within class/struct
* Also known as inner class/struct, methods are usually defined outside the outer class/struct.
* Prior to C++11, only type name, enumerators, and static members of outer could be accessed, but from C++11, they can be accessed like a friend class. so all members could be accessed.

* In the nested class/struct, inner can access to a outer class/struct, but converse is not established.
* The friend class declared in outer class can access only the private member of outer, not the inner, and the friend class declared in inner class can access only the private member of inner class likewise.
* Virtual methods can be inherited and overriden. And in the case of a non-static member, accessable the member function by creating an instance.



