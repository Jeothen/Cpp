# C# & .net Framework

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

    ...