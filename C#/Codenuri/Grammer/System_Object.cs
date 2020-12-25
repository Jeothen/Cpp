using System;

class Car : System.Object
{

}

class Point
{
    private int x = 0;
    private int y = 0;

    public Point(int xpos, int ypos)
    {
        x = xpos; y = ypos;
    }

    // In general, it is often overridden
    public override string ToString()
    {
        return string.Format($"x = {x}, y = {y}");
    }
}


class System_Object
{
    static void Main(string[] args)
    {
        Car c = new Car();
        c.ToString(); // All type derived from 'System.Object

        //      Car. // enable to use 2 static method 

        // ToString
       

        Point p1 = new Point(1, 11);
        Point p2 = new Point(2, 22);

        Console.WriteLine(p1.ToString());
        Console.WriteLine(p2.ToString());
    }
}

