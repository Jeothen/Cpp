using System;



// IComparable  - interface that originally served by System

// C# 1.0
interface IComparable2
{
    int CompareTo2(object other);
}


// All compareable object must be implemented IComparable interface

class Point : IComparable2
{
    private int x;
    private int y;
    public Point(int xpos, int ypos)
    {
        x = xpos;
        y = ypos;
    }
    public int CompareTo2(object other) // if Point is struct, boxing (copy to object other(heap))
    {
        Point pt = other as Point; // if Point is struct(valuetype), unboxing

        if (x > pt.x) return 1;
        else if (x == pt.x) return 0;
        return -1;
    }
}


/*
// C# 2.0 - genereic interface
interface IComparable3<T>
{
    int CompareTo3(T other);
}
*/

// value type
struct cPoint : IComparable<cPoint>, IComparable // overloading
{
    private int x;
    private int y;
    public cPoint(int xpos, int ypos)
    {
        x = xpos;
        y = ypos;
    }

    public int CompareTo(cPoint pt) // sametype, not boxing
    {
        if (x > pt.x) return 1;
        else if (x == pt.x) return 0;
        return -1;
    }

    public int CompareTo(object other) // object type
    {
        cPoint pt = (cPoint)other;

        if (x > pt.x) return 1;
        else if (x == pt.x) return 0;
        return -1;
    }
}


class Boxing2
{
    static void Main()
    {
        Console.WriteLine(10 < 20); 
        Console.WriteLine(10.CompareTo(20));  // if 10 > 20 : -1, same : 0, 10 < 20 : 1

        string s1 = "AA", s2 = "BB";
        //        Console.WriteLine(s1 < s2); error, relational operator only used for numeric associate type
        Console.WriteLine(s1.CompareTo(s2)); // almost type, enable to compare

        Point p1 = new Point(1, 1);
        Point p2 = new Point(2, 2);
        Console.WriteLine(p1.CompareTo2(p2));

        
        // apply c# interface 2.0 
        cPoint p3 = new cPoint(1, 1);
        cPoint p4 = new cPoint(2, 2);
        Console.WriteLine(p3.CompareTo(p4));
        object o2 = new cPoint(2, 2);
        Console.WriteLine(p3.CompareTo(o2)); 
    }
}