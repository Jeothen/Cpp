using System;

class Boxing
{
    static void Main()
    {
        
        int[] a1 = { 1, 2, 3 };
        object o1 = a1;
        a1[0] = 10;
        int[] a2 = (int[])a1;

        Console.WriteLine(a2[0]); // 10
        // stack : a1 / o1 / a2      heap : 10 2 3

        int n1 = 1; // valuetype  - stack
        // stack : n1(1)
        object o2 = n1;
        // copy stack n1(1) to heap (1)   - boxing
        n1 = 10;
        // copy heap(o2 reference - 1) to stack (n2 - 1)  - unboxing
        int n2 = (int)o2;

        Console.WriteLine($"{n1}, {n2}"); // 10, 1

        // when boxing/unboxing needed copy, so speed become lower

    }
}