# Call by value or reference

* Call by value
  * When a function is called, a separate temporary space for the function, a stack frame, is created in the memory space.
  * The stack frame consists of memory of function, return, and parameter
  * Since the value of the variable is copied and passed as a function argument, even if the value of the argument is changed with the characteristic of local value, the value of the external variable is not changed.



* Call by reference
  * When a function is called, a separate temporary space for the function, a stack frame, is created in the memory space.
  * When a function is called, a reference of a variable is passed as an argument, so when the value of an argument changes in the function, the value of the object passed as an argument is also changed.