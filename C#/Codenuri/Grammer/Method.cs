using System;


class Car
{
    private int speed;
    public void Go() { Console.WriteLine("Go"); }
    // Go(Car this) -> Go()
}

static class CarExtension
{
    public static void Stop(this Car c)
    {
//      c.speed = 10; // error - private
 //     c.SetSpeed(10); //  using setter/getter
        Console.WriteLine("Stop");
    }
    public static void Foo(this Car c, int a)
    {
        Console.WriteLine(a);
    }
}

static class StringEtension
{
    public static void test(this string a, int b)
    {
        Console.WriteLine($"{a},{b}");
    }
}

class Method
{
    /*
    public static int Sum(int a, int b)
    {
        return a + b;
    }
    */

    public static int Sum(params int[] arr) // array created in heap, so efficiency is lower
    {
        int s = 0;
        foreach (int i in arr) s += i;
        return s;
    }

    public static int Sum(int a, int b) 
    {
        return a + b;
    }

    public static void f1(params object[] arr)
    {
        foreach (object o in arr) Console.WriteLine(o.ToString());
    }

    public static void f2(int a, params int[] arr) { }
//    public static void f3(params int[] arr, int a) { } //  error , don't know how far the params are


    /*
    public static void t1(DateTime dt = DateTime.Now); // Varies with each run
    public static void t2(DateTime dt = new DateTime());
    public static void t3(DateTime dt = default(DateTime)); // compiler know default value
    */


    public static void Main()
    {
        int s1 = Sum(1, 2);  // match exactly same parameters, if there's not, params function
        int s2 = Sum(1, 2, 3);

        int s3 = Sum(new int[] { 1, 2 }); 
        int s4 = Sum(new int[] { 1, 2, 3 });

        Console.WriteLine($"{s1},{s2}, {s3}, {s4}");
        // params
        f1(1, 2.5, "test");

        // named parameters
        SetRect(10, 20, 30, 40);
        SetRect(y: 20, x: 10, width: 30, height: 40);

        // optional parameter
        foo(1, 2, 3); // 1 2 3
        foo(1, 2);    // 1 2 2
        foo(a: 10, b: 20); // 10 20 2



        // expression
        Console.WriteLine(Square(3));


        // extension method
        Car c = new Car();
        c.Go(); // Go(c)
        c.Stop(); // CarExtension.Stop(c)
        c.Foo(22); //

        string str = "string test";
        str.test(121);

    }

    public static void SetRect(int x, int y, int width, int height)
    {
        Console.WriteLine($"{x},{y},{width},{height}");
    }

    // Optional parameter (default parameter)
    public static void foo(int a, int b, int c = 2)
    {
        Console.WriteLine($"{a},{b},{c}");
    }

    //     public void e1(int a, int b = 0, int c); // error - If only 2 arguments are given, it is not known which argument to use

    public static int Square(int a) => a * a;

}