# Concept

* All values are objects, not just instances
* In CTS, c# data type is changed to .net framework data type.

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



#### Nullable

* reference type : using `null`  to indicate no object
* value type : cannot express no value (null)
* Nullable<T>
  * add no value (null) to value type  - can be use null
  * Nullable<T> = int + bool
  * int? : shorhand notation



#### Evis Operator

* null conditional operator
  * ?.  (method).  /   ?[    (array)
    * if right side is null, not operate left side
    * ex)  int? n = c1?.foo();    // foo can be null
  * ??    (nullable type)
    * if left side of `??`   is null, operate right side of `??`



#### Casting

* If there's a data loss in the casting, explicit casting needed.
* `is`  operator 
  * check reference variable is same as specific type
* two casting ways
  * NEW n = **(NEW)**obj;   -> if failed, exception occured
  * NEW n = obj **as** NEW  -> if failed, return null

* Conversion operator
  * OLD -> NEW  : public static explicit operator NEW(OLD obj)
  * conversion operator not called when using `as`  operator



### Boxing

* Boxing : The processing of copying what is stored in the stack like valuetype to heap
* Unboxing : Saving the values on the heap to a variable on the stack



#### Compare

* relational operator such as `< `  or `> ` , used for numeric associate type
* CompareTo() method used almost type, enable to compare
* IComparable interface
  * Interface containing rules for CompareTo method
  * Types with comparable sizes must implement `IComparable` interface
  * C# provides almost method rules as an interface.
  * IComparable 
    * C# 1.0 interface
    * use object as method argument
    * occured boxing / unboxing
  * IComaparable<T>
    * C# 2.0 interface
    * use Generic
    * not occurred boxing / unboxing
* It is recommended to implement both IComapable and IComparable<T> interfaces.



#### Equals

* **Equals** method
  * provided by the object class
  * Present in all types

* **CompareTo** method
  * Present only in types that implement IComparable or IComparable<T> interface
* When providing Equals(), it is better not to implement only the object type, but also implement the IEquatable<T> interface.

