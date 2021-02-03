# CRTP (Curiously Recurring Template Pattern)

* alternative to virtual functions and inheritance that can be used to give types properties at compile time



#### Formation

* General Form 

  * Methods within Base Class can access Derived members using templates

    

* Static Polymorphism 

  * The base class template is not instantiated long after the member function is declared and uses the members of the derived class within its own member function using a cast

  

* Object counter
  
  * Enable to  search the number of objects created and destroyed for a specified class using the object counter.



* Polymorphic chainin

  * The CRTP can be used to avoid Polymorphic chaining
  * When inheriting, inherit the derived type and maintain the derived object

  

* Polymorphic copy construction

  * When creating a copy of an object with a base class pointer, define a virtual copy function in the derived class.
  * With CRTP, all derived classes do not have to duplicate base class functions, thus avoiding duplication.
