// declare namespace
using System;
// static method of System.Console can be omitted
using static System.Console;


class basic
{
    static void Main(string[] args)
    {
        // System : namespace
        // Console : Class
        // WriteLine : static Method
        System.Console.WriteLine("Hello World!");
        // after declare namespace
        Console.WriteLine("test");
        // after declare static omitted
        WriteLine("test2");

        int n = 10;
        double d = 1.2;
        WriteLine(n);

        WriteLine("n={0} d={1} {0} ", n, d); // inside of {} is index
        // n=10 d=1.2 10
        // interpolated string
        WriteLine($"n={n} d={d} {n} ");

        WriteLine("C:\\A\\b.txt");
        // verbatim string 
        WriteLine(@"C:\A\b.txt");

        // ReadLine -> input one sentence to input buffer
        string s = Console.ReadLine();
        Console.WriteLine(s);

        // if input string is integer -> convert needed
        int n2 = Convert.ToInt32(s); // if s is string, exception occured
        Console.WriteLine(n2);

        string s1 = Console.ReadLine();
        Console.WriteLine(s);
        double d2 = Convert.ToDouble(s1);
        WriteLine(d2);

        
        // input one character to input buffer
        int c1 = Console.Read();
        Console.WriteLine(c1);

        int c2 = Console.Read();
        Console.WriteLine((char)c2);

        // If input buffer over than previous buffer, reading remnant of sentence
        string s2 = Console.ReadLine();
        Console.WriteLine(s2);

        // directly reading from keyboard, so there's no enter after reading read(line)()
        ConsoleKeyInfo key = Console.ReadKey(true); // if true, no echo to display
                                                    //      ConsoleKeyInfo key = Console.ReadKey();  default is false

        Console.WriteLine(key.KeyChar);
    }
}
