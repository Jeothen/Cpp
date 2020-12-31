using System;

class Array
{
    static void Main()
    {
        int[] arr1; // reference type
        int[] arr2 = new int[5]; // stored in heap  {0,0,0,0,0}
        int[] arr3 = new int[5] { 1, 2, 3, 4, 5 };
        int[] arr4 = new int[] { 1, 2, 3, 4 };
        int[] arr5 = { 1, 2, 3, 4, 5 };

        Type t = arr5.GetType();  // system.int32
        Console.WriteLine(t.FullName); 
        Console.WriteLine(t.BaseType);  // system.array
        Console.WriteLine(t.BaseType.BaseType.FullName); //system.object

        System.Array a;

        Console.WriteLine(arr5.Length); // 5
        Console.WriteLine(arr5.GetLength(0)); // 5,  using for two-dimension
        Console.WriteLine(arr5.GetValue(3));   // arr[3]
        Console.WriteLine(arr5.GetLowerBound(0)); // 0 - index
        Console.WriteLine(arr5.GetUpperBound(0)); // 4

        int[] arr6 = { 1, 2, 3, 4, 5 };  // heap {1,2,3,4,5}
        int[] arr7 = arr6;  // stack : arr6, arr7
        int[] arr8 = (int[])arr6.Clone();  // stored heap - {1,2,3,4,5}  {1,2,3,4,5}

        Console.WriteLine(arr6 == arr7); // true
        Console.WriteLine(arr6 == arr8); // false

        // Multi-dimension array

        int[,] darr1 = new int[3, 2];
        int[,] darr2 = new int[3, 2] { { 1,1},
                                        {2,2},
                                        {3,3}};
        int[,] darr3 = new int[,] { { 1,1},
                                    {2,2 },
                                    {3,3 }};
        int[,] darr4 = { { 1, 1 }, { 2, 2 }, { 3, 3 } };

        darr1[0, 0] = 10;
        darr1[0, 1] = 20;

        foreach (int i in darr1) Console.WriteLine(i);

        int[,,] ddarr1 = new int[2, 2, 2];

        // jagged array

        int[][] jarr = new int[3][]; // heap [] [] []

        jarr[0] = new int[3] { 1, 2, 3 };
        jarr[1] = new int[2] { 1, 2 };
        jarr[2] = new int[1] { 1 };

        // heap [] [] [] -> {1,2,3} {1,2} {1}

        int[][] jarr2 = new int[3][]
                                {
                                new int[3],
                                new int[2],
                                new int[1] };

    }
}