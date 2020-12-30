using System;

struct Point1 // -> stored in Stack  (value type)
{
    public int x, y;
    public Point1(int xpos, int ypos)
    {
        x = xpos; y = ypos;
    }
}

class Point2 // -> stored in heap (reference type)
{
    public int x, y;
    public Point2(int xpos, int ypos)
    {
        x = xpos; y = ypos;
    }
}

public struct Value_Reference_Type
{
    public static void Main()
    {
        Point1 p1 = new Point1(1, 1);
        // stack   p1(x=1,y=1)
        Point2 p2 = new Point2(2, 2);
        // reference
        // stack p2  -> heap (x=2,y=2)

        Point1 p3 = p1;
        // Copy
        // stadck  p1(x=1,y=1), p3(x=1,y=1)
        Point2 p4 = p2;
        // stack p2  -> heap (x=2,y=2)
        // stack p4  -> heap (x=2,y=2)

        p3.x = 2;
        Console.WriteLine(p1.x); // 1

        p2.x = 3;
        Console.WriteLine(p4.x); // 3

        // Int32 is struct, so int is value type

        int n1 = 1;
        int n2 = n1;

        n2 = 10;
        Console.WriteLine(n1); // 1   n2 copy n1

        // array derived from system.Array
        System.Array arr; // Array is class, so array is reference type
        int[] arr1 = { 1, 2, 3 };
        // {1,2,3} is stored in heap
        int[] arr2 = arr1;
        // arr1, arr2 is stored in stack
        arr2[0] = 4;
        // reference type
        Console.WriteLine(arr1[0]); // 4


        // string is class, so string is reference type
        System.String s; 
        string s1 = "Hello";
        string s2 = s1;

        if (s1 == s2) Console.WriteLine("Same");
        s2 = "hello";
        // string is immutable so s2 = new string("No hello")
        if (s1 != s2) Console.WriteLine("Diff");
        Console.WriteLine(s1);

        Type t = s1.GetType();
        Console.WriteLine(t.IsValueType);
    }
}