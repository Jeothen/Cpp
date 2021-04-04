# Intermediate Language

- by c# compiler, c# program is transformed to Executable file, independent on CPU / OS
- IL Code can be used in the virtual environment of each OS (CLR, Common Language Runtime)
- C++ or VB can be changed to IL by using the .net compiler

---

* .il  : source code extension

* ```shell
  $ ilasm ~.il 
  
  # need to be .entrypoint / ret in il code
  ```

* if call function, It writes the return value of the function at the same time as the call command.

  ```c#
  	call void goo()
  ```

* Instead of using an alias like int as a parameter of a function, int32 used in cli is used.

  ```c#
  .method static void hoo(int32 a, int32 b) cil managed {}
  ```

*  IL, namespace -> class using '.' like c# ,  class->method using '::' like C++

  ```
  	call void System.Console::WriteLine()
  ```

  



