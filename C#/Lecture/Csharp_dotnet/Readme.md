# C# & dot net Framework

#### BASIC CODE

* Main function
  * static void Main()
  * static void Main(String[] args)
  * static int Main()
  * static int Main(string[] args)
* terms
  * member function => method
  * member data => field



* System.Console Class
  * static class that offered standard input/output function
  * Console.WriteLine
    * interpolated string : In front of "" using `$` ,  Variables can be entered directly in {}.
    * verbatim string : In front of "" using @, Prints characters such as `\\` as they are without applying regular expressions
    * Read() : reading one character 
    * Readline() : reading one sentence
    * Convert class : using method (specific data type), transform data type.
    * ConsoleKeyInfo : reading from keyboard, not input buffer



* Type, Variable, Literal
  * If reading not initailized variable, Compile error occured.
  * Literal notation
    * ob111 - binary / 010 - octal / ox11 - hexadecimal   : same as C++
    * Digit notation : using `_`
  * var
    * It is same as auto of C++.
    * inference left value type from right value
  * casting
    * C# doesn't support implicit casting, but explicit casting



* CTS of CLR Data Type 

  * int : Int32 or System.Int32
* double : Double or System.Double
  * string : String or System.String
* Everything in C# is an object
    * Certain values are also objects. Example is `   10.CompareTo(20);`
  * Certain datatype are also objects. Example is   `int.Equals();`



* Class
  * The access specifier must be applied to all members
  * Inheritance is used through `:` and access specifiers cannot be used for inheritance.
  * Online C++, use `()` to Construct an object
  * Use ` new`  in front of the data type when creating a field or method with the same name as a member in the base clas



* Method

  * In Java, all method is virtual method.   
  * In C++ and C#, method can be virtual method or not.   So, If not virtual method redefine needed, using `new` for not happened compile warning.

  * Use `override` , not `new `  when redefining a virtual method.  `new`  using when creating other method.







* Interface
  * Defining the names of methods used by multiple classes
  * In C# development, design the interface first. After that, the class provides a method by implementing a specific interface.
  * Interface implement
    * Not using `override`
    * method type is virtual or not

