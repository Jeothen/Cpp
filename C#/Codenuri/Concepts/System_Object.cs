using System;

namespace Concepts
{
    class System_Object
    {
        static void Main(string[] args)
        {
            // int : type // 10 : object of int type
            10.ToString();
            // int.Parse();
            
            int n1;
//            Console.WriteLine(n1); Compile error, not initialized
            n1 = 10;
            Console.WriteLine(n1);

            double n2 = 10;
            var n3 = n2; // double

            string s1 = "AAA";  // c# type
            String s2 = "BBB";  // .net datatype
            System.String s3 = "CCC"; // using System

           
        }
    }
}
