using System;

class Point // class -> reference type
{
    private int x = 0;
    private int y = 0;

    public Point(int xpos, int ypos)
    {
        x = xpos; y = ypos;
    }

    public override bool Equals(object obj)
    {
        Point pt = (Point)obj; // as
        return x == pt.x && y == pt.y; // value type compare
    }

    // operator override
    public static bool operator==(Point p1, Point p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
    // in C#, if operator == is implemented, =! must be implemented
    public static bool operator != (Point p1, Point p2)
    {
        return p1.x != p2.x || p1.y != p2.y;
    }
}


struct S
{
    private int x;
    private int y;

    public S(int xpos, int ypos)
    {
        x = xpos; y = ypos;
    }
}


class System_Object
{
    static void Main(string[] args)
    {
        Point p1 = new Point(1, 1);
        Point p2 = p1;
        Point p3 = new Point(1, 1);

        // == opereator
        // check reference same 
        Console.WriteLine(p1 == p2); // True
        Console.WriteLine(p1 == p3); // False  -> True (after operator override)

        // Equals()  - virtual method
        // check reference same
        Console.WriteLine(p1.Equals(p2)); // True
        Console.WriteLine(p1.Equals(p3)); // False -> True (after method override || operator override)

        // Equals is virtual method, so user override method


        object o1 = new Point(1, 1);
        object o2 = o1;
        object o3 = new Point(1, 1);

        // == opereator
        // check reference same 
        Console.WriteLine(o1 == o2); // True
        Console.WriteLine(o1 == o3); // False / not Point


        Console.WriteLine(o1.Equals(o2)); // True
        Console.WriteLine(o1.Equals(o3)); // True  override object type



        //-----struct - stored in stack

        S s1 = new S(1, 1);
        S s2 = s1;

        // basically not offered, but enable to use with == operator
        //      Console.WriteLine(p1==p2); // It's reference compare - heap



        // It's same memcmp in c++, check all the memories match
        Console.WriteLine(s1.Equals(s2));
    }
}

