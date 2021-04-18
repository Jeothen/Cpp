.assembly ex06{}
.assembly extern mscorlib {}


.class public Program
{
    .method public instance void foo() cil managed // instance method - default in c#
    {
        ldstr "foo"
        call void [mscorlib]System.Console::WriteLine(string)
        ret
    }
    .method public specialname rtspecialname instance void .ctor() cil managed // Basic Constructor
    {
        // call Basic class constructor
        ldarg.0  // first parameter is this
        call instance void [mscorlib]System.Object::.ctor()
        ret
    }

    .method public static void Main() cil managed
    {
        .entrypoint   // if not defined entrypoint, not calling Main()

        // Program p = new Program()
        .locals init(class Program V_0)
        newobj instance void Program::.ctor()  // newobj - memory allocation, create object in heap / .ctor() - call Constructor

        stloc.0  // locate object address to 0 variable 
        
        // p.foo()
        
//        call void Program::foo()

        ldloc.0
        callvirt instance void Program::foo() // call 0 variable's foo()

        ret
    }
}
