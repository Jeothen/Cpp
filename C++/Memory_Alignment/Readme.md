# Memory Alignment

* C++ Classes or Structures increase in size by the size of alignment.
* If the size of structures or classes less than multiple size of the alignment, the padding fills the remaining of the multiple size.



* In the case of a 32-bit (64-bit) os, if alignment is given in multiples of 4 bytes (8bytes) , the memory can be referenced by moving only one space, so the process can be operated quickly, because memory bus width is 32-bit (64-bit)



### C++11

* alignof

  * querying the alignment
  * Alignment requirements of the largest element in the structure

  

* alignas

  * controlling alignment
  * Memory size can be forcibly allocated.
  * When Using Struct, alignas must be bigger than max size of element

  

### C++17

* operator new

  * Allocates memory space without calling constructor

  * ```c++
    void* test = operator new(sizeof(double));  // just allocate memory space
    
    class test_class;
    
    new (test) test_class(sample); // call Constructor
    ```

    