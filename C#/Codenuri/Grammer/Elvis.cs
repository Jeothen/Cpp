using System;
namespace Grammer
{
    class Car
    {
        public int color = 10;
        public void Go() { Console.WriteLine("go"); }
    }

    class Elvis
    {
        public static Car CreateCar(int speed)
        {
            if (speed > 200) return null;
            return new Car();
        }
        public static void Main()
        {
            Car c1 = CreateCar(100);
            c1.Go();
            Car c2 = CreateCar(300);
            //         n2.Go(); // exception occured

            // ?. operator -> elvis operator
            // if left side is null, not operated and return null
            c1?.Go();
            c2?.Go();

            // int n1 = c1.color; ok
            // int n1 = c2.color; // if c2 is null, exception error occured
            // int n1 = c2?.color; // error, there's a possible c2 is null

            int? n1 = c2?.color;  // if c2 is not null, n1 is not null

            // array //

            int[] arr = null; // array is reference type

            // int n2 = arr[0]; // error occured

            int? n2 = arr?[0];

            // ?? operator
            Car c3 = CreateCar(300) ?? new Car();  // if left side of '??' (CreateCar(300)) is null, right side of '??' (new Car()) operated

            int? n3 = null;
            int n4 = n3 ?? 0;
        }

    }
}
