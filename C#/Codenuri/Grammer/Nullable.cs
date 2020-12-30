using System;


class Nullable
{
    // public static int foo()
    public static Nullable<int> foo()
    {
        bool fail = false;
        if (fail) return null;
        return 1;
    }

    public static void Main()
    {
        // string : reference type
        string s1 = "Hello";
        string s2 = null; // there's no object

        Nullable<int> n1 = 10;
        Nullable<int> n2 = null;

        if (n2 == null) { }

        int? n3 = null; // Nullable<int> n3 = null

        // casting //
//      (int)n3; // error occured

        int? t1 = 10;
        int t2 = 20;

        t1 = t2; // int? = int
 //     t2 = t1; // error - > int = int?  there's no bool type
        t2 = (int)t1; // int = int?->int

        Console.WriteLine(t2); // 20

        int? N1 = null;
        int? N2 = 20;
        int? N3 = N1 + N2; // if even one element is bool type, Nullable is bool type

        Console.WriteLine(N3 == null);  // True
        Console.WriteLine(N3);
    }
}