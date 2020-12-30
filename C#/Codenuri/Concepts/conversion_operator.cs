using System;

class Point
{
    private int x;
    private int y;
    public Point(int xpos, int ypos)
    {
        x = xpos;
        y = ypos;
    }
    public override string ToString()
    {
        return string.Format($"{x}, {y}");
    }

    public static explicit operator int(Point pt)
    {
        return pt.x;
    }
    public static explicit operator Point(int n)
    {
        return new Point(n, n);
    }
}

class conversion_operator
{
    static void Main()
    {
        double d = 1.2;
        int n1 = (int)d; // not data loss

        Point pt = new Point(1, 2);
        // Point -> int  :  explicit operator
        int n2 = (int)pt; // explicit..
        Console.WriteLine(n2);

        // contro
        Point pt2 = (Point)n2; // point->int
        Console.WriteLine(pt2);  // pt2.ToString()

//        Point pt3 = n2 as Point; // if using as operator, conversion operator not called.
    }
}