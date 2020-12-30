using System;

// CompareTo : IComparable, IComparable<T>
// Equals : object

/*
interface IEquatable<T>
{
    bool Equals(T other);
}*/

struct Point3 : IEquatable<Point3>
{
    private int x, y;

    public Point3(int xpos, int ypos)
    {
        x = xpos; y = ypos;
    }

    public bool Equals(Point3 pt) // IEquatable
    {
        Console.WriteLine("Point");
        return x == pt.x && y == pt.y;
    }

    public override bool Equals(object obj)
    {
        Console.WriteLine("Object");
        Point3 pt = (Point3)obj;
        return x == pt.x && y == pt.y;
    }
}

class Boxing3 {
    static void Main()
    {
        Point3 p1 = new Point3(1, 1);
        Point3 p2 = new Point3(2, 2);
        object o2 = new Point3(2, 2);

        Console.WriteLine(p1.Equals(p2));
        Console.WriteLine(p1.Equals(o2));
    }
}