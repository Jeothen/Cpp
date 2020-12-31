# Grammer



#### Array

* Array is a reference type, and variables are stored on the stack, but values are stored on the heap.
* All arrays are derived from system.array
* The Clone() method copies the same array to the heap.



* Multi - dimension Array
  * int[, ] arr = new int[y, x]
  * Int[,,] arr1 = new int[z,y,x]

* Jagged Array
  * Int [][][] [] arr = new int[3] [] { new int[3], new int[2] , new int[1]};



#### Callby

* reference type
  * Basically, the `int` variable stores the value on the stack, but if the `ref` variable is used, the value is not saved and the value of another variable is referred.
* The parameter can be received as a value or a reference. If it is a reference, the parameter to be sent also uses `ref`
* out parameter  :  If return two values, it can be do it with `ref`   or `out`
  * ref
    * enable read / write
    * must be initialized
  * out
    * enable only write
    * can be not initialized value

* So, Out is often used when returning more than one result.

* Passing the reference type as `value` can change the state of the object, but it cannot contain a new object.
* Passing the reference type as `reference` can change the state of the object, but it can contain a new object.
  * It's acting like double pointer in C language



#### Method

* Variable Parameter
  * Passing an `array` as an argument
  * Using variable length parameters such as `params`
* Params
  * The method in which params is used as an argument creates an array on the heap, so there is a performance degradation.
  * Matches the same parameters first, and uses params method when none

* Named Parameter
  * When passing arguments, use'argument name
  * When naming argument names, the order is irrelevant

* Optional parameter

  * Save default value to parameter

  * default must be specified from the end
    * If only some arguments are given, it is not known which argument to use
  * What is determined by execution time, not determined at compile time, cannot be used as an argument.

* Expression
  * If the method implementation is simple, indicate the return value after =>
* Extension method
  * Syntax for adding a new method without modifying the existing class
  * Provided as a static method of a static class



#### Property

* public filed problem
  * Problems with the object's state may occur due to incorrect external access
* Encapsulation
  * Put the field private and access it using setter and getter methods
  * In C#, there is a `property` syntax that automatically creates setter and getter methods.
* Define property as get{} set{}, and then apply by get/set according to context
* It is actually a method, but when used, it is used like a field

* When the property name is Age, Compiler creates set_Age() get_Age() method for setter and getter