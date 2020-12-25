using System;

class Car : System.Object
{

}

class Point
{
    private int xpos = 0;
    private int ypos = 0;

    public Point(int x, int y)
    {
        xpos = x; ypos = y;
    }

    // In general, it is often overridden
    public override string ToString()
    {
        return string.Format($"x = {xpos}, y = {ypos}");
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

