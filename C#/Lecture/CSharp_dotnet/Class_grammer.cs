using System;


class Base
{
    public int data1 = 1;
    public int data2 = 2;
    public int data3 = 3;

    public void Foo() { Console.WriteLine("Base foo"); }
    public void Goo() { Console.WriteLine("Base goo"); }

    public virtual void Hoo() { Console.WriteLine("Base Hoo"); }

    public virtual void Koo() { Console.WriteLine("Base Koo"); }
}

class Derived : Base // not using access specifier
{
    // compile warning -> new

    public int data1 = 4;
    public new int data3 = 5;

    public void Foo() { Console.WriteLine("Derived foo"); }
    public new void Goo() { Console.WriteLine("Derived goo"); }

    public override void Hoo() { Console.WriteLine("Derived Hoo"); } // overriding,  virtual of C++ changed to override in C#

    public new void Koo() { Console.WriteLine("Derived Koo"); } // not redefined, other virtual method
}

class Class_grammer
{
    static void Main()
    {
        Derived a = new Derived();

        Console.WriteLine(a.data1); // 4

        Console.WriteLine(((Base)a).data1); // 1 compile warning occured, but running -> using new
        // new notation
        Console.WriteLine(((Base)a).data3); // 3 not compile error occured.

        Console.WriteLine(a.data2); // 2

        Base b1 = new Base();  // b1 is Base object
        b1.Foo();  // Base Foo


        Derived d1 = new Derived();
        d1.Foo();  // Derived Foo

        Base b2 = new Derived();
        b2.Foo();   // java doesn't support virtual method, so Derived Foo in java
                    // C++ / Since C# support virtual method, Check if Foo method is virtual method or not
                    // If it isn't virtual method, call the reference type. -> Base Foo()

        b2.Goo();  // Base Goo 
        b2.Hoo();  // Derived Hoo
        b2.Koo();  // Base Koo

        // --> So using override, when base class using virtual
    }
}
