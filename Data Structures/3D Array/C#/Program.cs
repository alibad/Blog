using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            //  Array 3 Dimensions
            int x = 4, y = 5, z = 6;

            //  Array Iterators
            int i, j, k;

            //  Allocate 3D Array
            int[,,] array3D = new int[x, y, z];

            //  Access array elements
            for (i = 0; i < x; i++)
            {
                Console.WriteLine(i);

                for (j = 0; j < y; j++)
                {
                    Console.WriteLine();

                    for (k = 0; k < z; k++)
                    {
                        array3D[i, j, k] = (i * y * z) + (j * z) + k;
                        Console.Write("\t{0}", array3D[i, j, k]);
                    }
                }

                Console.WriteLine('\n');
            }
        }
    }
}
