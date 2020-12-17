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

