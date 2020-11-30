# Rules of 3 / 5 / 0



### Rule of Three (C++ 03)

* If a class requires a user-defined destructor, a user-defined [copy constructor, or a user-defined copy assignment operator, it  requires all three because classes manage resources consistently
* When a copy is performed, the shared reference count is incremented 1, and as soon as the count reaches 0, it is deallocated from memory 



### Rule of Five (C++11)

* move constructor and move assignment added as new member functions
* When Class requires member function of 5 member functions and move semantics, five member function all required.
* If the rule of three is followed, no optimization will occur, but no compilation errors will occur.





### Rule of Zero (C++11)

* Basically, In the rule of five, all five member functions must be listed.
* If the rule of zero is applied, the compiler defines the member function as default or deleltes it according to the settings.





### Self Allocation Protection

* When using the copy assignment operator, in very rare cases an object that references itself can be created.
* So, If object allocates itself, It should be written login to prevent objects from referencing themselves.