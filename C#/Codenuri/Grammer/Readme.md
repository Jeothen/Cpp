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