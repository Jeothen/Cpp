// declare namespace
using System;
// static method of System.Console can be omitted
using static System.Console;


class basic_grammer
{
    static void Main()
    {
        int n1 = 10;
        int n2; // C#, If not initialized Compile error occured
        n2 = 1;
        Console.WriteLine($"{n2}");

        int n3 = n1;
        int n4 = 0b1000; // Binary notation / 0x~ hexadecimal

        int n5 = 1_000_000; // Digit notation(ignoring compilation)

        var n6 = 10; // define type from right value
        var d1 = 3.4; // same role as auto of C++

        // Doesn't support implicit casting
//      int n7 = d1; // C#, It occured error.
        // explicit casting
        int n7 = (int)d1;



        int a1 = 10;   // int transformed to int32  on CTS of CLR
        Int32 a2 = 10;

        System.Int32 a3 = 1;  // CLR data type

        double d2 = 0.0;
        Double d3 = 1.0;


        int[] arr = { 1, 2, 3, 4, 5 };
        arr[0] = 6; arr[1] = 7;
        //  arr[10] = 7;  exception out of range occured
        try
        {
            arr[10] = 7;
        }
        catch (IndexOutOfRangeException e)
        {
            Console.WriteLine("Out of Range Occured");
        }
    }
}