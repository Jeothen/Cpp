using System;

class Animal { }
class Dog : Animal
{
    public void Cry() { Console.WriteLine("Cry..."); }
}

class casting
{
    public static void foo(Animal a)
    {
        //  a.Cry();

        // Down Casting
        /*   if failed when casting or using method, exception occured
           
        Dog d = (Dog)a;  // casting error 
        d.Cry();*/
        Dog d1 = a as Dog; // if failed, return null
        if (d1 == null)
        {
            Console.WriteLine("null");
        }       


        // find method - try  catch
        if (a is Dog)
        {
            Console.WriteLine("Dog correct");
            Dog d2 = (Dog)a;
            d2.Cry();

        }

    }

    static void Main()
    {
        // casting 1//////
        int n = 3;
        double d = 3.4;

        d = n; // there's no data loss
//        n = d; // there's a data loss -> explicit casting needed
        n = (int)d;


        // casting 2 ///////
        foo(new Animal());  // if failed when Downcasting, exception occured, so using 'as' operator

        foo(new Dog());


        // using nullable

        object obj = n;
        int? n1 = obj as int?; // ok
        Console.WriteLine(n1);


    }
}
