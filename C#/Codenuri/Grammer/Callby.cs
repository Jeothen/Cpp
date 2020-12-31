using System;

class Point
{
    public int x = 0;
    public int y = 0;
    public Point(int xpos, int ypos) { x = xpos; y = ypos; }
}

class Callby
{
    public static void inc1(int n)
    {
        ++n;
    }

    public static void inc2(ref int n)
    {
        ++n;
    }

    // ref - only initialized value
    public static int prev_next_number1(int n, ref int r)
    {
        int val = r; // read/write
        r = n + 1;
        return n - 1;
    }
    // out  - can be not initialized value
    public static int prev_next_number2(int n, out int r)
    {
//        int val = r;  // error - only write 
        r = n + 1;
        return n - 1;
    }

    // reference type 
    public static void f1(Point p) // Point p = p1;   stack : p, p1 / heap : (1,1)
    {
        p.x = 2;  // heap (1,2) - change object
        p = new Point(5, 5);  // heap (1,2), (5,5) / p1 is continuously refer (1,1)
    }

    public static void f2(ref Point p)  // p refer p2
    {
        p.x = 3;  // heap (3,2)
        p = new Point(5, 5);  // p -> p2 -> (3,2) --> (5,5)
    }


    public static void Main()
    {
        int n1 = 10; // stack
        int n2 = n1; // stack
        n2 = 20;
        Console.WriteLine($"{n1}, {n2}"); //10, 20

        // reference variable
        int n3 = 10; // stack
        ref int n4 = ref n3; // n4 -> n3
        n4 = 20;  //  n3 : 20
        Console.WriteLine($"{n3}, {n4}");

        // not reference
        int rn1 = 10;
        inc1(rn1);
        Console.WriteLine(rn1);

        // reference
        int rn2 = 10;
        inc2(ref rn2);
        Console.WriteLine(rn2);

        // apply - two return
        int tmp1 = 10;
        int tmp2 = 20;
        // ref
        int res1 = prev_next_number1(tmp1, ref tmp2);
        Console.WriteLine($"{tmp1}, {tmp2}");
        // out
        tmp1 = 10;
        tmp2 = 20;
        int res2 = prev_next_number2(tmp1, out tmp2);
        Console.WriteLine($"{tmp1}, {tmp2}");


        // reference type
        Point p1 = new Point(1, 1);
        // stack : p1  / heap : (1,1)
        f1(p1);  // Point is reference type
        Console.WriteLine(p1.x); // 2

        // ref
        Point p2 = new Point(2, 2);
        // stack : p2  / heap : (2,2)
        f2(ref p2); 
        Console.WriteLine(p2.x); // 5
    }
}