# Const Correctness

* It is useful when the instance has no transformation or there are parameters that should not be changed by mistake.
* If there is a `const` before parentheses in the method implementation part, the value of instance cannot be modified within the method.



* If instance has const, it can also using with overloading. In const, const type object is called, and in non-const, non-const  type object is called.  In the case of const, only data reading is possible, and in the case of non-const, data read/write is possible.



* When a non-const value is received as a const parameter of a method, const overload is executed.



