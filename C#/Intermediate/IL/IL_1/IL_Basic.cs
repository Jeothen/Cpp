using System;

struct Point
{
    public int x, y;
}



class IL_Basic
{
    static void Main(string[] args)
    {
        Point pt1;
        Point pt2 = new Point();  // using Initialization in IL code
//        Console.WriteLine($"{pt1.x}"); // error occured
        Console.WriteLine($"{pt2.x}"); 
    }
}
