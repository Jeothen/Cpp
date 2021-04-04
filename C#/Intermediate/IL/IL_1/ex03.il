.assembly ex03 {} 
// add reference
.assembly extern mscorlib {}


.method static void foo() cil managed
{
	.entrypoint 

	// c# : System.Console.WriteLine()

	// IL, namespace -> class using '.' like c# ,  class->method using '::' like C++ 
	call void [mscorlib]System.Console::WriteLine()  // System in mscorlib assembly

	ldstr "Hello, IL"

	call void [mscorlib]System.Console::WriteLine(class System.String)

	ret
}