# Const Correctness

* It is useful when the instance has no transformation or there are parameters that should not be changed by mistake.
* If there is a `const` before parentheses in the method implementation part, the value of instance cannot be modified within the method.
  
* In the case of a const type instance, const must be declared in front of the parentheses when calling a method.
  
  
  



* If instance has const, it can also using with overloading. In const, const type object is called, and in non-const, non-const  type object is called.  In the case of const, only data reading is possible, and in the case of non-const, data read/write is possible.

* When a non-const value is received as a const parameter of a method, const overload is executed.



* When passing int as a function parameter, the implemented function can receive const int / const int& as parameter
* However, in the case of const type in class/struct or global function, the return value must be const type.



* Member variable using mutable keyword can be changed even if intance is const type
*  If constructor not complemented, so const type value is not initialized, error occured when compile time



### Const Ketword

* Non-const pointer/reference can not bind to const variable.



* int can not assign to const reference
* int reference can not assign to const pointer



* The const class cannot use non-const functions.

* The const qualifier overloads a general function, so when overloading within a class, const_casting must be performed.




### Const Member function

* const member function can not be assignment on a class data member.
* it can be modified class data member value in directly, like using a pointer. just can not assignment on a data member



### Constexpr

* Const keyword executed at compile time
* An error occurs when the data executed at runtime is in the constexpr function/data



* If constexpr vs # ifdef
  * `#ifdef`  is evaluated at preprocessing time. and it cannot be used to conditionally compile code based on the value of a template parameter.  and  gramatical error codes can be discard.
  * ` if constexpr` is used for conditionally compile code based on the value of template parameter.  condition should be const expression.