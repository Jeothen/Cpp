using System;

class People
{
    public int age = 0;
}

class Program
{
    static void Main()
    {
        People p = new People();

        p.age = 10;
        p.age = -5;
    }
}