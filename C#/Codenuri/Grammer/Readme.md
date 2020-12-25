# Grammer

* All type derived from `System.Object`



#### System.Object

* There are 7 methods in system.object
  * 2 static method 
    * Equals(object A, object B)
    * ReferenceEquals(object A, object B)
  * 3 virtual method
    * ToString()
    * GetHashCode()
    * Equals(object A)
  * 1 non-virtual method
    * GetType()
  * 1 protected method 
    * MemberwiseClone()

* User defined methods often override 3 virtual methods



---

### Value | Reference Type

* In C++, when the user allocates each variable, the place to be stored in memory is designated, whereas in C#, the place to be stored in memory is determined through the type.
* The class is stored on the heap(**reference type**) and the struct(**value type**) is stored on the stack.  But the variables referencing the class are stored on the stack.

* Value type
  * struct, enum
  * Types related to numbers such as int, double
* Reference type
  * class, interface, deletgate
  * object, string, array...

* Since all C# objects are derived from System.Object, create a type object with the Gettype() method and check with the return value of isvaluetype.



---

#### Equality

* == operator

  * checking reference equaility
  * useful specific type operation, but base class type such as `object`  not applied.

  

* Equal virtual method
  * checking reference equality
  * there's a many case using for check same value

