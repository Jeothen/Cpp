### Class vs struct

* The difference from struct

  * default, member variable, member function.

  * base classes

    * struct is public / class is  private.

  * Class has a constructor and destructor, enforcing invariant

  * Struct just simple collection of values.

  * Class can be used to declare template parameters

    

  * In C++, struct and class have no distinction except for the above difference.

---

# Class

* Access Specifiers

  * public : Everyone
  * protected : class itself and derived clasees and friend classes.
  * private : class itself and friend classes
* If static member variable is declared as global variable, Can be accessed from any instance of class(struct)



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



### Virtual Inheritance

* If inherited as a private/public class (struct) rather than a virtual class (struct), it may be ambiguous.

  * For example, when there is an inheritance relationship of A->B / A->C and an inheritance relationship of B->D / C->D, 

     In D, A's constructor is called twice.  

  * And, When accessing A from D, it is unclear whether to access A instance created in B or C.

* So, When inheriting multiple classes (struct), make diamond diagrams form through virtual

  * In the case of A->B / A->C through virtual, B and C share and use one instance of A together.

